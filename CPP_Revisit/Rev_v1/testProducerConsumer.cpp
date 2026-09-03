#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <climits>
#include <atomic>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> Que;
constexpr int MAX_SIZE = 5;
std::atomic<bool> done{false};
std::atomic<int> producers{2};
void producer(int thread_id)
{
    for (int i = 1; i <= 10; i++)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]
                { return Que.size() < MAX_SIZE; });
        Que.push(i);
        std::cout << "producer: " << thread_id << " has produced item: " << i << "\n";
        lock.unlock();
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    {
        producers--;
        if (producers == 0)
        {
            done.store(true, std::memory_order_release);
            cv.notify_all();
        }
    }
}

void consumer(int thread_id)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]
                { return !Que.empty() || done.load(std::memory_order_acquire); });
        if (!Que.empty())
        {
            int item = Que.front();
            Que.pop();
            std::cout << "consumer: " << thread_id << " has consumed item: " << item << "\n";
        }
        else if (done)
        {
            break;
        }
        lock.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    {
        std::jthread p1(producer, 1);
        std::jthread p2(producer, 2);
        std::jthread c1(consumer, 1);
        std::jthread c2(consumer, 2);
        std::jthread c3(consumer, 3);
        std::jthread c4(consumer, 4);
    }
    std::cout << "All threads are finished... !!!" << "\n";
    return 0;
}
