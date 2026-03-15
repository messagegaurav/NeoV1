// SLIDING WINDOW

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string LongestSeq(const string &text)
{
    if (text.empty())
        return "";
    int left = 0, right = 0;
    int maxSize = 0, currLen = 0, startIndex = 0;

    int len = text.size();
    unordered_set<char> Set;

    while (right < len)
    {
        if (Set.find(text[right]) == Set.end())
        {
            Set.insert(text[right]);
            right++;
        }
        else
        {
            Set.erase(text[left]);
            left++;
        }

        currLen = right - left;
        if (maxSize < currLen)
        {
            maxSize = currLen;
            startIndex = left;
        }
    }
    return text.substr(startIndex, maxSize);
};

string LongestSeqMap(const string &text)
{
    if (text.empty())
        return "";
    unordered_map<char, int> charMap;
    int left = 0, maxSize = 0, startIndex = 0;

    for (int right = 0; right < (int)text.size(); right++)
    {
        if (charMap.count(text[right]) && charMap[text[right]] >= left)
            left = charMap[text[right]] + 1;
        charMap[text[right]] = right;
        if (right - left + 1 > maxSize)
        {
            maxSize = right - left + 1;
            startIndex = left;
        }
    }
    return text.substr(startIndex, maxSize);
}

int main()
{
    cout << "-- Set approach --" << endl;
    cout << LongestSeq("abcabcbb") << endl;
    cout << LongestSeq("bbbbb") << endl;
    cout << LongestSeq("pwwkew") << endl;
    cout << LongestSeq("") << endl;
    cout << LongestSeq("abcdef") << endl;

    cout << "-- Map approach --" << endl;
    cout << LongestSeqMap("abcabcbb") << endl;
    cout << LongestSeqMap("bbbbb") << endl;
    cout << LongestSeqMap("pwwkew") << endl;
    cout << LongestSeqMap("") << endl;
    cout << LongestSeqMap("abcdef") << endl;
    return 0;
}
