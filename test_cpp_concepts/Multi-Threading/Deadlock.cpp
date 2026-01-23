#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

std::mutex mtx1, mtx2;

void thread1()
{
    std::scoped_lock lock(mtx1, mtx2);
    std::cout << "Thread 1: Got both locks" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "Thread 1: Releasing locks" << std::endl;
}

void thread2()
{
    std::scoped_lock lock(mtx2, mtx1);
    std::cout << "Thread 2: Got both locks" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "Thread 2: Releasing locks" << std::endl;
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}