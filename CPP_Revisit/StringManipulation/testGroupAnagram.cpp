#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAangram(const vector<string> &vec)
{
    unordered_map<string, vector<string>> Map;
    for (const auto &ch : vec)
    {
        string key = ch;
        sort(key.begin(), key.end());
        Map[key].push_back(ch);
    }

    vector<vector<string>> result;
    for (const auto &ch : Map)
    {
        result.push_back(ch.second);
    }
    return result;
}

int main()
{
    vector<string> vec = {"ate", "eat", "bat", "mat", "fear", "race", "care", "tea", "acer"};
    auto itr = groupAangram(vec);
    for (const auto &ch : itr)
    {
        cout << "[ ";
        for (const auto &ph : ch)
        {
            cout << " " << ph;
        }
        cout << " ] ";
        cout << endl;
    }
    return 0;
}