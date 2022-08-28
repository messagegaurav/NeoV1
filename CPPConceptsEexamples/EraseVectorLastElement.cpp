/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-24 23:39:47
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-25 01:20:20
 */

#include "mychrono.h"
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>

void VecEraseLastElement();
void CheckErase();

Chrono Clock;
int main()
{
    Clock.Start();
    // VecEraseLastElement();
    CheckErase();
    Clock.Stop();

    Clock.Time("micro");
    cout << endl;
    return 0;
}

void printVec(const vector<int> &_vec)
{
    for (auto &itr : _vec)
        cout << "\n val: " << itr;
}

void VecEraseLastElement()
{
    vector<int> myVec = {0, 1, 2, 3, 4, 5};

    for (auto itr = myVec.begin(); itr != myVec.end(); itr++)
    {
        if (*itr % 2 != 0)
        {
            itr = myVec.erase(itr);

            // check if you dont you tend to increment post end and it crashes
            if (itr == myVec.end())
                break;
        }
    }

    printVec(myVec);
}

void CheckErase()
{
    vector<int> myVec(10);
    iota(myVec.begin(), myVec.end(), 0);

    // auto itr = myVec.erase(remove(myVec.begin(), myVec.end(), 3), myVec.end());

    // or

    // auto itr = find(myVec.begin(), myVec.end(), 3);
    // itr = myVec.erase(itr);\

    // or

    // auto itr = erase(myVec, 3); // from c++ 20 onwards combines remove operation in itself

    // or

    // using erase predicate
    auto itr = erase_if(myVec, [](int x)
                        { return (x == 3); });

    printVec(myVec);
}