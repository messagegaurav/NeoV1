/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-04 23:51:33
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-05 00:12:51
 */

#include "mychrono.h"
#include <mutex>
#include <thread>
#include <semaphore>

 //TODO: implement prodcuer consumer problem using classes.

class sMutex
{

public:

    static sMutex& getInstance()
    {
        if (myMutex != nullptr)
            return *myMutex;
        myMutex = new sMutex();
        return *myMutex;
    }

    sMutex(const sMutex&) = delete;
    sMutex& operator=(const sMutex&) = delete;
    ~sMutex()
    {
        if (myMutex != nullptr)
        {
            delete myMutex;
            myMutex = nullptr;
        }
    }

    mutex& getMutex()
    {
        return mu;
    }

    sem_t& getSem()
    {
        return mySem;
    }

private:
    mutex mu;
    sem_t mySem;
    inline static sMutex* myMutex;
    sMutex();
};

class Producer
{
public:

    void* StartProduction()
    {
        lock_guard<mutex> locker(sMutex::getInstance().getMutex());




    }

private:


};

class Consumer
{



};


int main()
{



    cout << endl;
    return 0;
}