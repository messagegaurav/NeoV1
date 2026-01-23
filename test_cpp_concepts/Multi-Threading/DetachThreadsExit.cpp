#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void detachedTask()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        std::cout << "Detached thread completed its task." << std::endl;
    }
    cv.notify_one();
}

int main()
{
    std::thread t1(detachedTask);
    t1.detach();
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []
                { return ready; });
        std::cout << "Main thread completed its task." << std::endl;
    }
    std::cout << "Main: Thread signaled exit. Program ending safely.\n";
    return 0;
}