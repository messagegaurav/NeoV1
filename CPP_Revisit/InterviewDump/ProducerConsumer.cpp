#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>

using namespace std;

mutex mtx;
condition_variable cv;
bool done = false;
constexpr size_t MAX_SIZE = 5;
queue<int> Queue;
void producer(int id)
{
    for (int i = 0; i < 10; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []()
                { return Queue.size() < MAX_SIZE; });

        // pushing to buffer
        Queue.push(i);
        cout << "Produced data: " << i << " Size of buffer now: " << Queue.size() << endl;
        cv.notify_one();
        lock.unlock();
    }
    {
        lock_guard<mutex> lock(mtx);
        done = true;
        cout << "Producer finished Producing... !!! " << endl;
        cv.notify_all();
    }
}

void consumer(int id)
{
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []()
                { return !Queue.empty() || done; });
        if (done && Queue.empty())
        {
            cout << "Done processing the produced data...!!!!" << endl;
            break;
        }
        else
        {
            int data = Queue.front();
            Queue.pop();
            cout << "Consumer: " << id << " data: " << data << endl;
            lock.unlock();
            cv.notify_one();
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
}

int main()
{
    thread producer1(producer, 1);
    thread consumer1(consumer, 1);
    thread consumer2(consumer, 2);
    thread consumer3(consumer, 3);

    producer1.join();
    consumer1.join();
    consumer2.join();
    consumer3.join();

    cout << "Threads Exited !!!!" << endl;

    return 0;
}