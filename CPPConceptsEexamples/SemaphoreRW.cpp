/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-05 23:15:40
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-05 23:27:25
 */


#include "mychrono.h"
#include <mutex>
#include <semaphore>
#include <thread>

mutex mu;
sem_t myPdSem;
sem_t myCmSem;

constexpr int sodaCan = 10;

Use Cases: 
1. Once consumer takes all can then they wait and producer starts and fills the can. 
2. If consumer takes ones... producer immd fills the can. 
3. 

void* Producer(void* args)
{

    sem_wait(&myCmSem);
    lock_guard<mutex> locker(mu);

    cout << "\n Refilling Soda cans...";

    this_thread::sleep_for(chrono::seconds(4));

    sem_post(&myPdSem);

    return 0;
}

void* Consumer(void* args)
{

    sem_wait(&myPdSem);

    lock_guard<mutex> locks(mu);

    cout << "\n Got my soda can....";

    this_thread::sleep_for(chrono::seconds(4));

    sem_post(&myCmSem);



    return 0;
}

int main()
{

    sem_init(&myPdSem, 0, sodaCan);
    sem_init(&myCmSem, 0, 0);

    cout << endl;
    return 0;
}