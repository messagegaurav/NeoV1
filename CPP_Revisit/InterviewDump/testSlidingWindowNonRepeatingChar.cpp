#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

string slidingWindow(string str)
{
    int len = (int)str.size();
    if (len < 1)
        return "";

    unordered_set<char> Set;
    int left = 0, right = 0;
    int maxlen = 0, start = 0;

    while (right < len)
    {
        while (Set.count(str[right]) > 0)
        {
            Set.erase(str[left]);
            left++;
        }
        Set.insert(str[right]);
        if (right - left + 1 > maxlen)
        {
            maxlen = right - left + 1;
            start = left;
        }
        right++;
    }
    return str.substr(start, maxlen);
}

int main()
{
    string str = "abcabcbb";
    cout << "Longest non repeating string: " << slidingWindow(str);
    cout << "\n";
    return 0;
}