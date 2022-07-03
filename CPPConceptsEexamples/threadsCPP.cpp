/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-03 18:00:51
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-03 19:10:07
 */

#include "mychrono.h"
#include <thread>
#include <mutex>
#include <condition_variable>

class CondVar
{

public:
    CondVar()
    {
        cout << "\n object created...";
        balance = 0;
    }

    void credit(int _bal)
    {
        unique_lock<mutex> lockCR(mu);
        cout << "\n Credit transaction:  " << _bal;
        balance += _bal;
        flag = true;
        this_thread::sleep_for(chrono::seconds(10));
        cout << "\n Credit balance now:      " << balance;
        lockCR.unlock();
        cvar.notify_all();
        // or you can use cvar.notify_one() to notify single thread.
    }

    void debit(int _inr)
    {
        unique_lock<mutex> lockDB(mu);
        cout << "\n Debit transaction:      " << _inr;
        cvar.wait(lockDB, [this]()
            { return this->flag; });
        balance -= _inr;
        // this_thread::sleep_for(chrono::seconds(10));
        cout << "\n Balance debited ...remaining bal: " << balance;
        lockDB.unlock();
    }

    virtual ~CondVar()
    {
    }

    static int getBalance()
    {
        return balance;
    }

private:
    mutex mu;
    condition_variable cvar;
    inline static int balance;
    bool flag = false;
};

int main()
{

    CondVar* myCondVar = new CondVar();

    thread t1(&CondVar::credit, myCondVar, 200);

    thread t2(&CondVar::debit, myCondVar, 50);

    thread t5(&CondVar::debit, myCondVar, 30);

    thread t6(&CondVar::debit, myCondVar, 20);

    thread t3(&CondVar::debit, myCondVar, 100);

    cout << "\n\n Total outstanding Balance:      " << CondVar::getBalance();

    t1.join();
    t2.join();
    t3.join();
    t5.join();
    t6.join();

    delete myCondVar;

    cout << endl;

    return 0;
}
