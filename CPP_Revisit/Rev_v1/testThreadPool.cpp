#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>
#include <functional>
#include <queue>

class ThreadPool
{
public:
    void enqueue(std::function<void()> task);
    ThreadPool(int numThreads);
    ~ThreadPool();

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> stop{false};
};

ThreadPool::ThreadPool(int numThreads)
{
    for (int i = 1; i <= numThreads; i++)
    {
        workers.emplace_back([this, i]
                             {
        while(true)
    {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] {return stop || !tasks.empty();});
            if (stop && tasks.empty())
            {
                return;
            }
            task = std::move(tasks.front());
            tasks.pop();
        }
        std::cout << "Worker: " << i << "   executing task \n";
        task();
    } });
    }
}

void ThreadPool::enqueue(std::function<void()> task)
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        tasks.push(task);
    }
    cv.notify_one();
}

ThreadPool::~ThreadPool()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        stop = true;
    }
    cv.notify_all();
    for (auto &thread : workers)
    {
        thread.join();
    }
}

int main()
{
    ThreadPool pool(5);
    pool.enqueue([]
                 { std::cout << " Task A is executing..!!!"; });
    pool.enqueue([]
                 { std::cout << " Task B is executing..!!!"; });
    pool.enqueue([]
                 { std::cout << " Task C is executing..!!!"; });
    pool.enqueue([]
                 { std::cout << " Task D is executing..!!!"; });

    std::cout << "Main thread has done enqueueing all the tasks now .. !!!! \n";
    return 0;
}