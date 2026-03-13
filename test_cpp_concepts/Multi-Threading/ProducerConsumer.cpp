#include <thread>
#include <mutex>
#include <iostream>
#include <queue>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> buffer;
bool finished = false;
const int MAX_BUFFER_SIZE = 5;

void producer(int id)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        {
            std::unique_lock<std::mutex> lock(mtx);

            // Wait if buffer is full
            cv.wait(lock, []
                    { return buffer.size() < MAX_BUFFER_SIZE; });

            buffer.push(i);
            std::cout << "Producer " << id << " produced: " << i
                      << " (buffer size: " << buffer.size() << ")" << std::endl;
        }
        cv.notify_one();
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        finished = true;
        std::cout << "Producer " << id << " finished" << std::endl;
    }
    cv.notify_all();
}

void consumer(int id)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []
                { return !buffer.empty() || finished; });

        if (buffer.empty() && finished)
        {
            std::cout << "Consumer " << id << " exiting" << std::endl;
            break;
        }

        if (!buffer.empty())
        {
            int value = buffer.front();
            buffer.pop();
            std::cout << "Consumer " << id << " consumed: " << value
                      << " (buffer size: " << buffer.size() << ")" << std::endl;
            lock.unlock();

            cv.notify_one(); // Notify producer that space is available

            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    }
}

int main()
{
    std::thread producer_thread(producer, 1);
    std::thread consumer1(consumer, 1);
    std::thread consumer2(consumer, 2);
    std::thread consumer3(consumer, 3);

    producer_thread.join();
    consumer1.join();
    consumer2.join();
    consumer3.join();

    std::cout << "All threads completed" << std::endl;
    return 0;
}

while (n)
{
    return (n >> i) & 1;
}

bool isPrime(int n)
{
    if (n <= 1)
        return 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return true;
        }
    }
    return false;
}

printPrime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(n))
            cout << " " << i;
    }
}