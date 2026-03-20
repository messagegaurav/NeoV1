// 1. remove all duplicates from a string
// 2. Remove duplicates from a sorted array
// 3. Remove duplicates and keep the count

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

string remDupFromString(const string &str)
{
    unordered_set<char> Set;
    string temp;
    temp.reserve(str.size());
    for (const auto &ch : str)
    {
        if (!Set.count(ch))
        {
            Set.insert(ch);
            temp += ch;
        }
    }

    return temp;
}

void remDupSortedArr(vector<int> &vec)
{
    int j = 0; // slow
    int len = vec.size();
    for (int i = 1; i < len; i++)
    {
        if (vec[i] != vec[j])
        {
            j++;
            vec[j] = vec[i];
        }
    }
    vec.resize(j + 1);
}

void remDupCountOccurence(const string &str)
{
    unordered_map<char, int> Map;
    string temp;
    temp.reserve(str.size());
    for (const auto &ch : str)
    {
        if (Map[ch] < 1)
        {
            temp += ch;
        }
        Map[ch]++;
    }

    cout << "final string: " << temp << endl;

    for (const auto &ch : Map)
    {
        cout << ch.first << " : " << ch.second << endl;
    }
}
int main()
{
    string text = "banana";
    cout << "final: " << remDupFromString(text) << endl;

    vector<int> vec = {1, 1, 1, 2, 2, 3, 3, 5, 7, 8};
    remDupSortedArr(vec);
    for (const auto &val : vec)
        cout << " " << val;
    cout << endl;

    string str = "banaananananabanana";
    remDupCountOccurence(str);
    cout << endl;

    return 0;
}