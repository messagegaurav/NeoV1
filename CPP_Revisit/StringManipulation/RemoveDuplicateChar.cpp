#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// to remove consecutive dupl
// void remDuplicate(string &str)
// {
//     string temp;
//     int i = 0, j = str.size() - 1;
//     while (i < j)
//     {
//         if (str[i] != str[i + 1])
//         {
//             temp += str[i];
//         }
//         i++;
//     }
//     temp += str[i];

//     str = "";
//     str = temp;
// }

// to remove all duplicate
void useFreqArr(string &str)
{
    string temp;
    vector<int> freq(256, 0);
    for (auto &ch : str)
    {
        if (freq[ch] < 1)
        {
            freq[ch]++;
            temp += ch;
        }
    }
    str = temp;
}

// using map
void useSet(string &str)
{
    unordered_set<char> Set;
    string temp;
    for (auto &ch : str)
    {
        if (Set.count(ch) == 0)
        {
            Set.insert(ch);
            temp += ch;
        }
    }
    str = temp;
}
int main()
{
    string text = "programming";
    // remDuplicate(text);
    // useFreqArr(text);
    useSet(text);
    cout << "final string: " << text << endl;
    return 0;
}