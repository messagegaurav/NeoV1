#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> anagramGroup(const vector<string> &vec)
{
    unordered_map<string, vector<string>> uMap;

    for (const auto &ch : vec)
    {
        string key = ch;
        sort(key.begin(), key.end());
        uMap[key].push_back(ch);
    }

    vector<vector<string>> result;
    for (auto &mapWords : uMap)
    {
        result.push_back(mapWords.second);
    }
    return result;
}

int main()
{
    vector<string> vec = {"ate", "eat", "tea", "race", "care", "acre"};

    // want group of anagram strings
    vector<vector<string>> vecGroup = anagramGroup(vec);

    for (auto &itr : vecGroup)
    {
        for (auto &ch : itr)
        {
            cout << " " << ch;
        }
        cout << endl;
    }
    cout << "\n";
    return 0;
}