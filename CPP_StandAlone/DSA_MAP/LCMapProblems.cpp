/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-09 22:52:41
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-13 00:16:47
 */

#include "mychrono.h"
#include <map>
#include <algorithm>


 //Q. find pair of values that sums to the given total from the list. 
 // Input: {10, 2, 15, 40, 8, 16}, target = 18

//below solution will work with unique numbers only.
// and repetition of pairs.

Chrono myClock;

void findPair(int* a, int size, int total)
{

    map<int, int> uMap;
    for (int i = 0; i < size; i++)
    {
        uMap[a[i]] = i;
    }

    for (auto itr : uMap)
    {
        map<int, int>::iterator myItr;
        myItr = uMap.find(total - itr.first);
        if (myItr != uMap.end())
            cout << "\n first:  " << myItr->first << "  , " << itr.first;
    }

}


int main()
{

    int a[] = { 10, 2, 15, 40, 8, 16 };

    int total = 0;

    int size = sizeof(a) / sizeof(a[0]);

    cout << "\n size of a: " << size;

    cout << "\n enter total number: ";
    cin >> total;

    myClock.Start();

    findPair(a, size, total);

    myClock.Stop();

    myClock.Time("micro");

    cout << endl;
    return 0;
}