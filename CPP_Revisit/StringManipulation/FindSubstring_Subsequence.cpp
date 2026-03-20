#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

void allSubString(const string &str)
{
    set<string> Set;
    string temp;
    if (!str.empty())
    {
        for (int i = 0; i < str.length(); i++)
        {
            temp.clear();
            temp += str[i];
            Set.insert(temp);
            for (int j = i + 1; j < str.length(); j++)
            {
                temp += str[j];
                Set.insert(temp);
            }
        }
    }

    for (const auto &subStr : Set)
    {
        cout << " " << subStr << endl;
    }
}

// void allSubString1(const string &str)
// {
//     set<string> Set;

//     for (int i = 0; i < str.length(); i++)
//     {
//         for (int len = 1; len <= str.length() - i; len++)
//         {
//             Set.insert(str.substr(i, len));
//         }
//     }

//     for (const auto &substr : Set)
//         cout << substr << endl;
// }

void allSubSequence(const string &str)
{
    if (!str.empty())
    {
        int n = str.length();
        set<string> Set;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            string temp;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    temp += str[i];
                }
            }
            Set.insert(temp);
        }
        for (const auto &subSeq : Set)
        {
            cout << " " << subSeq << endl;
        }
    }
}
int main()
{
    string text = "ABC";
    allSubString(text);
    // allSubString1(text);
    allSubSequence(text);
    return 0;
}