#include <atomic>
#include <iostream>
#include <array>
#include <thread>
#include <chrono>
#include <cstdlib>

constexpr int BUF_SIZE = 16;

std::array<int, BUF_SIZE> buffer;
std::atomic<int> head(0), tail(0);
std::atomic<bool> stop_flag(false);

// Cleanup function called at program exit
void cleanup_threads() {
    std::cout << "Program exiting, stopping detached threads...\n";
    stop_flag.store(true, std::memory_order_relaxed);
    // Give threads time to see the flag and exit
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void worker_thread()
{
    while (!stop_flag.load(std::memory_order_relaxed))
    {
        // Thread work here...
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Detached worker exiting\n";
}

int main()
{
    // Register cleanup function to run at program exit
    std::atexit(cleanup_threads);
    
    std::thread worker(worker_thread);
    worker.detach();
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    std::cout << "Main function ending\n";
    return 0;  // cleanup_threads() will be called automatically
}