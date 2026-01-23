#include <atomic>
#include <iostream>
#include <array>
#include <thread>
#include <chrono>

constexpr int BUF_SIZE = 16;

std::array<int, BUF_SIZE> buffer;
std::atomic<int> head(0), tail(0);
std::atomic<bool> stop_flag(false);

void ISR_HANDLER(int value)
{
    int currentHead = head.load(std::memory_order_relaxed);
    int nextHead = (currentHead + 1) % BUF_SIZE;
    if (nextHead != tail.load(std::memory_order_acquire))
    {
        buffer[currentHead] = value;
        head.store(nextHead, std::memory_order_release);
    }
    else
    {
        std::cout << "Buffer is full, dropping value " << value << "\n";
    }
}

void worker_thread()
{
    while (!stop_flag.load(std::memory_order_relaxed))
    {
        int currentTail = tail.load(std::memory_order_relaxed);
        if (currentTail != head.load(std::memory_order_acquire))
        {
            int value = buffer[currentTail];
            tail.store((currentTail + 1) % BUF_SIZE, std::memory_order_release);
            std::cout << "Worker thread got value " << value << "\n";
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    std::cout << "Worker thread exiting\n";
}

void simulateISR()
{
    int value = 1;
    while (!stop_flag.load(std::memory_order_relaxed))
    {
        std::cout << "ISR thread got value " << value << "\n";
        ISR_HANDLER(value++);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "ISR thread exiting\n";
}

int main()
{
    std::thread worker(worker_thread);
    std::thread isr(simulateISR);

    std::this_thread::sleep_for(std::chrono::seconds(10));

    // Signal threads to stop
    stop_flag.store(true, std::memory_order_relaxed);

    // Wait for threads to finish properly
    worker.join();
    isr.join();

    std::cout << "All threads finished cleanly\n";
    return 0;
}
