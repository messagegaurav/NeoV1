#include <iostream>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <queue>
#include <thread>
#include <chrono>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;

const unsigned int MAX_BUFFER = 5;

bool done = false;

void producer(int threadId)
{
    for (int i = 0; i < 10; i++)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []
                { return done || buffer.size() < MAX_BUFFER; });

        if (done)
            break;

        buffer.push(i);
        lock.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(int threadId)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        {
            cv.wait(lock, []
                    { return !buffer.empty() || done; });

            if (!buffer.empty())
            {
                int item = buffer.front();
                buffer.pop();
                std::cout << "Consumer: " << std::this_thread::get_id() << " consumed item: " << item << "\n";
            }
            else if (done)
                break;
        }
        lock.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    std::thread p1(producer, 1);
    std::thread p2(producer, 2);

    std::thread c1(consumer, 1);
    std::thread c2(consumer, 2);
    std::thread c3(consumer, 3);
    p1.join();
    p2.join();

    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();

    c1.join();
    c2.join();
    c3.join();

    return 0;
}