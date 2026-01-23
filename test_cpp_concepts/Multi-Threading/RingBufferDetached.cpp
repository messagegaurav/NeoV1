#include <atomic>
#include <iostream>
#include <array>
#include <thread>
#include <chrono>
#include <signal.h>
#include <cstdlib>

constexpr int BUF_SIZE = 16;

std::array<int, BUF_SIZE> buffer;
std::atomic<int> head(0), tail(0);
std::atomic<bool> stop_flag(false);

// Signal handler to set stop flag
void signal_handler(int signal) {
    std::cout << "\nReceived signal " << signal << ", stopping threads...\n";
    stop_flag.store(true, std::memory_order_relaxed);
}

void ISR_HANDLER(int value)
{
    int currentHead = head.load(std::memory_order_relaxed);
    int nextHead = (currentHead + 1) % BUF_SIZE;
    if (nextHead != tail.load(std::memory_order_acquire))
    {
        buffer[currentHead] = value;
        head.store(nextHead, std::memory_order_release);
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
            std::cout << "Worker got: " << value << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Worker thread exiting\n";
}

void simulateISR()
{
    int value = 1;
    while (!stop_flag.load(std::memory_order_relaxed))
    {
        ISR_HANDLER(value++);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "ISR thread exiting\n";
}

int main()
{
    // Register signal handlers
    signal(SIGINT, signal_handler);   // Ctrl+C
    signal(SIGTERM, signal_handler);  // Termination signal
    
    std::thread worker(worker_thread);
    std::thread isr(simulateISR);
    
    // Detach threads
    worker.detach();
    isr.detach();
    
    std::this_thread::sleep_for(std::chrono::seconds(10));
    
    // Set stop flag and give threads time to exit
    stop_flag.store(true, std::memory_order_relaxed);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    std::cout << "Main exiting\n";
    return 0;
}