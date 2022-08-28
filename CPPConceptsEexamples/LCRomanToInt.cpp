/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-13 00:15:12
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-14 14:43:40
 */

#include "mychrono.h"
#include <map>
#include <algorithm>

Chrono myClock;

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

int ConvertRomanToInt(string& str)
{

    // parse  using character 
    // check if character exists put its value to a total
    // if current element is > total then decrement by 1 

    map<char, int> myMap;
    myMap = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

    int total = 0;
    int previous = 0;

    auto itr = myMap.find(str[0]);
    total = total + itr->second;
    previous = itr->second;

    for (int i = 1; i < str.size(); i++)
    {
        int curr = 0;
        auto itr = myMap.find(str[i]);

        if ((itr->second > previous))
        {
            curr = itr->second - previous;
            curr = curr - previous;
        }
        else
        {
            curr = curr + itr->second;
        }
        previous = itr->second;
        total = total + curr;
    }

    return total;
}



// keep previous 
// match if current is less than previous then : total = total + (current - previous)


int main()
{

    string str;
    cout << "\n Enter roman string: ";
    getline(cin, str);

    myClock.Start();
    cout << "\n\n Integer equivalent is:  " << ConvertRomanToInt(str);

    myClock.Stop();
    myClock.Time("micro");



    cout << endl;
    return 0;
}