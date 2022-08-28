/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-30 23:11:57
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-30 23:38:35
 */

#include <iostream>
#include <mutex>
#include <thread>
#include <algorithm>
#include <list>

using namespace std;

list<int> myList;

mutex myMutex;

void addToList(int _num)
{
    cout << __FUNCTION__ << "       :started" << endl;
    lock_guard<mutex> guard(myMutex);
    for (int i = 0; i < 100; i++)
    {
        i = i * _num;
        myList.push_back(i);
    }
}

void printList()
{
    cout << __FUNCTION__ << "   : started" << endl;
    lock_guard<mutex> guard(myMutex);
    for (auto itr : myList)
    {
        cout << "     " << itr;
    }
}

int main()
{
    int num = 2;
    thread t1(&addToList, num);

    num = 4;
    thread t2(&addToList, num);

    thread t3(&printList);

    t1.join();
    t2.join();
    t3.join();

    cout << "\n\n";
    return 0;
}
