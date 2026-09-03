#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <functional>

class ThreadPool
{
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;

public:
    ThreadPool(int numOfThreads)
    {
        for (int i = 0; i < numOfThreads; i++)
        {
            workers.emplace_back([this]
                                 {
                    while(true)
                    {
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lock(mtx);
                            cv.wait(lock, [this]{
                            return stop || !tasks.empty();});

                            if (stop && tasks.empty())
                            return;

                            task = std::move(tasks.front());
                            tasks.pop();                        
                        }
                        task();
                    } });
        }
    }

    void enqueue(std::function<void()> task)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (stop)
            {
                throw std::runtime_error("ThreadPool stopped");
            }
            tasks.push(std::move(task));
        }
        cv.notify_one();
    }

    ~ThreadPool()
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            stop = true;
        }

        cv.notify_all();
        for (auto &worker : workers)
        {
            worker.join();
        }
    }
};

int main()
{
    ThreadPool pool(3);
    for (int i = 0; i < 10; i++)
    {
        pool.enqueue([i]
                     { std::cout << "Exeuting task " << i << " on thread: " << std::this_thread::get_id() << '\n'; });
    }
    return 0;
}