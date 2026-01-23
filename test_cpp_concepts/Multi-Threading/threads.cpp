#include <thread>
#include <iostream>

void task()
{
    std::cout << "Thread is executing task." << std::endl;
}

int main()
{
    std::thread t1(task);
    if (t1.joinable())
    {
        t1.join();
    }
    std::cout << "Main thread completed." << std::endl;
    return 0;
}