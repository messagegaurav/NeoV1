/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-04 23:04:10
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-04 23:11:11
 */

#include "mychrono.h"
#include <mutex>
#include <condition_variable>
#include <thread>

enum class eStatus
{
    WRITING = 0,
    READING
};

eStatus status = eStatus::WRITING;
static int value = 0;

mutex mu;
condition_variable cvar;

void* Writer(int writerId)
{
    status = eStatus::WRITING;
    lock_guard<mutex> writeLock(mu);
    cout << "\n Writer: " << writerId << "  going to write....";
    value += 10;
    this_thread::sleep_for(chrono::seconds(4));
    cout << "\n Writer: " << writerId << "  completes !!!";
    status = eStatus::READING;
    cvar.notify_all();
    return 0;
}

void* Reader(int readerId)
{
    unique_lock<mutex> readLocker(mu);
    cvar.wait(readLocker, []()->bool { return (status == eStatus::READING) ? true : false;});
    cout << "\n\n Reader: " << readerId << "    value read:     " << value;
    readLocker.unlock();
    return 0;
}


int main()
{
    thread t1(Writer, 1);
    thread t2(Reader, 1);
    thread t3(Reader, 2);
    thread t4(Reader, 3);
    thread t5(Writer, 2);
    thread t6(Reader, 4);
    thread t7(Reader, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();

    cout << endl;

    return 0;
}