#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// using frequency array
string longestSeq(const string &text)
{
    int n = text.length();
    int left = 0, right = 0;
    vector<int> vec(256, 0);
    int currLen = 0, maxLen = 0, startIndex = 0;
    for (int right = 0; right < n; right++)
    {
        char ch = text[right];
        vec[ch]++;
        while (vec[ch] > 1)
        {
            vec[text[left]]--;
            left++;
        }

        currLen = right - left + 1;
        if (currLen > maxLen)
        {
            maxLen = currLen;
            startIndex = left;
        }
    }
    return text.substr(startIndex, maxLen);
}

// using set now

string useSet(const string &str)
{
    if (str.empty())
        return "";
    int n = str.length();
    unordered_set<char> Set;
    int left = 0;
    int maxlen = 0, startIndex = 0;

    cout << "\n=== Starting useSet ===\n";

    for (int right = 0; right < n; right++)
    {
        char ch = str[right];
        cout << "\n[right=" << right << "] ch='" << ch << "' | ";

        // Remove duplicates
        while (Set.count(ch) > 0)
        {
            cout << "DUPLICATE! Removing '" << str[left] << "' at left=" << left << " | ";
            Set.erase(str[left]);
            left++;
        }

        Set.insert(ch);
        cout << "Inserted '" << ch << "' | ";

        // Print current set
        cout << "Set={";
        for (const auto &c : Set)
            cout << c;
        cout << "} | ";

        int currLen = right - left + 1;
        cout << "Window=[" << left << "," << right << "] len=" << currLen;

        if (currLen > maxlen)
        {
            maxlen = currLen;
            startIndex = left;
            cout << " <- NEW MAX! startIndex=" << startIndex;
        }
    }

    cout << "\n\n=== Final: startIndex=" << startIndex << ", maxlen=" << maxlen << " ===\n";
    return str.substr(startIndex, maxlen);
}

int main()
{
    string text = "abcdbcabbcab";
    auto str = longestSeq(text);
    cout << "Final string: " << str << endl;

    auto str1 = useSet(text);
    cout << " Final string: " << str1 << endl;
    return 0;
}