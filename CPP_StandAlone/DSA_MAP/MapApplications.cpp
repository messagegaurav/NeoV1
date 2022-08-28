/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-26 15:05:29
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-27 00:19:56
 */

#include "mychrono.h"
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

Chrono myClock;

using namespace std;
void findFrequencyUsingMap(map<string, int> &myMap);
void findFrequencyUnorderedMap(unordered_map<string, int> &myMap);

void printVal(auto &myMap);

int main()
{

    // using ordered Map complexity O(log n)

    myClock.Start();
    map<string, int> myMap;
    unordered_map<string, int> myUnMap;
    findFrequencyUsingMap(myMap);
    myClock.Stop();
    myClock.Time("micro");

    // using Unordered Map complexity O(1)

    myClock.Start();
    findFrequencyUnorderedMap(myUnMap);
    myClock.Stop();
    myClock.Time("micro");
    printVal(myMap);
    cout << endl;
    return 0;
}

// count the frequency for each word and print the unique strings
// if you dont assign a value to map element it will take by default as 0 value

void findFrequencyUsingMap(map<string, int> &myMap)
{
    vector<string> myVec = {"abc", "bcd", "cca", "abc", "dcb", "bcd"};

    // insert word into map as key
    // increment the frequency

    for (auto itr : myVec)
    {
        myMap[itr] = myMap[itr] + 1;
    }
}

void printVal(auto &myMap)
{
    for (auto itr : myMap)
        cout << "\n string: " << itr.first << "   frequency: " << itr.second;
}

void findFrequencyUnorderedMap(unordered_map<string, int> &myMap)
{
    vector<string> myVec = {"abc", "bcd", "cca", "abc", "dcb", "bcd"};

    // insert word into map as key
    // increment the frequency

    for (auto itr : myVec)
    {
        myMap[itr] = myMap[itr] + 1;
    }
}

// count how many words appeared twice

int countWords(string list[], int n)
{
    map<string, int> myMap;
    int count = 0;
    for (int i = 0; i < n; i++)
        myMap[list[i]] = myMap[list[i]] + 1;

    for (auto it : myMap)
    {
        if (it.second == 2)
        {
            count++;
        }
    }
    return count;
}

// find frequency for number of 1s in the list

int findFrequency(vector<int> v, int x)
{
    map<int, int> myMap;

    int count = 0;
    for (auto itr : v)
    {
        myMap[itr] = myMap[itr] + 1;
    }

    count = myMap[x];

    return count;
}