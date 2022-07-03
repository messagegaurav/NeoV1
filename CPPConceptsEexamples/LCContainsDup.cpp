/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-23 15:12:57
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-23 15:42:04
 */

 //Problem: 

 // - If any number duplicates return true else false.

 // - <1,2,3,4,5,1> 

 // - sort vector method
 // - map method using frequency check (bad time and space complextiy)
 // - map ( try using size if size doesnt increment means duplicate found)


#include "mychrono.h"
#include <algorithm>
#include <vector>
#include <map>


Chrono myClock;

bool containsDuplicate(vector<int>& nums) {

    // if list of number is larger use map.

    // map<int, int> myMap;
    // int size = 0;
    // for (auto& itr : nums)
    // {
    //     size = myMap.size();
    //     myMap[itr] = myMap[itr] + 1;
    //     cout << "\n map size: " << myMap.size();
    //     if (size == myMap.size())
    //     {
    //         cout << "\n -> " << itr;
    //         return true;
    //     }
    // }
    // return false;


    // if list of numbers is smaller user sorted vector. 
    sort(nums.begin(), nums.end());
    for (auto& itr : nums)
        cout << "  " << itr;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            cout << "\n =>    " << nums[i];
            return true;
        }
    }
    return false;
}

int main()
{

    vector<int> myVec = { 1,2,3,4,2 };

    myClock.Start();

    (containsDuplicate(myVec)) ? cout << "\n Yeyy dup found..." : cout << "\n no dup ...";

    myClock.Stop();

    myClock.Time("micro");
    cout << endl;
    return 0;
}





