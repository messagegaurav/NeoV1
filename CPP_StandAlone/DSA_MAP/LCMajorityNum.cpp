/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-14 14:42:42
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-14 15:29:09
 */

#include "mychrono.h"
#include <map>
#include <algorithm>


 // Q. find the majority element that exists more than n/2 times in the array[n].

int majorityElement(vector<int>& nums)
{
    int num = 0;
    map<int, int> myMap;

    // map<element, count> and take all the vector elements
    // while inserting increase the count if number is same.
    // if count > n/2 its gonna be max already in the list, return it.

    for (auto& itr : nums)
    {
        myMap[itr] = myMap[itr] + 1;
        if (myMap[itr] > (nums.size() / 2))
        {
            num = itr;
            break;
        }
    }
    return num;
}

int main()
{


    vector<int> myVec = { 3,3,3,3,5,3,3,1,2,5,5,5,5,5,5,5,5,5,5,5 };
    // vector<int> myVec = { 3,1,3 };

    cout << "\n\n Majority element is:    " << majorityElement(myVec);


    cout << endl;
    return 0;
}