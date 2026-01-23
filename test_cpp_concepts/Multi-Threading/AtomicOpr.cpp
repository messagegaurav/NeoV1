#include <thread>
#include <iostream>
#include <atomic>
#include <vector>

std::atomic<int> counter(0);

std::atomic<bool> flag(false);
void increment()
{
    for (int i = 0; i < 10; i++)
    {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

void set_flag()
{
    while (flag.load(std::memory_order_acquire) == false)
    {
    }
    std::cout << "Worker thread proceeding...\n";
}

void exchangeValues(int exchange, int newVal)
{
    if (counter.compare_exchange_strong(exchange, newVal))
    {
        std::cout << "Exchanged!\n";
    }
    else
    {
        std::cout << "Exchange failed!\n";
    }
}

int main()
{
    std::vector<std::thread> thread;
    for (int i = 0; i < 10; i++)
    {
        thread.emplace_back(increment);
    }
    for (auto &t : thread)
    {
        t.join();
    }
    std::cout << "Counter value: " << counter << std::endl;

    std::thread worker(set_flag);
    flag.store(true, std::memory_order_release);
    worker.join();

    int exchange = 100, newVal = 10;
    exchangeValues(exchange, newVal);
    std::cout << "Counter value: " << counter << std::endl;
    exchangeValues(0, 20);
    std::cout << "Counter value: " << counter << std::endl;
    return 0;
}
