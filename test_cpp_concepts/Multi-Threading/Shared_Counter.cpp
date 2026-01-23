#include <thread>
#include <mutex>
#include <iostream>

std::mutex mtx;
int sharedCounter = 0;
void shared_counter()
{
    for (int i = 0; i < 10000; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        sharedCounter++;
    }
}

int main()
{
    std::thread t1(shared_counter);
    std::thread t2(shared_counter);

    t1.join();
    t2.join();
    std::cout << "Final count: " << sharedCounter << std::endl;
    return 0;
}