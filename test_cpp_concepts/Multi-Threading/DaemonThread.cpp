#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>

std::atomic<bool> stop_flag(false);

void daemon_thread()
{
    // Set thread as daemon-like (low priority, background work)
    while (!stop_flag.load(std::memory_order_relaxed))
    {
        std::cout << "Daemon working...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "Daemon thread exiting\n";
}

class ThreadManager {
public:
    ThreadManager() {
        worker = std::thread(daemon_thread);
        worker.detach();
    }
    
    ~ThreadManager() {
        std::cout << "ThreadManager destructor - stopping daemon\n";
        stop_flag.store(true, std::memory_order_relaxed);
        // Brief wait for daemon to see the flag
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
private:
    std::thread worker;
};

// Global instance ensures destructor runs at program exit
ThreadManager global_thread_manager;

int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Main ending\n";
    return 0;  // global_thread_manager destructor will run
}