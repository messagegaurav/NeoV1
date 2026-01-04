#include <bits/stdc++.h>
using namespace std;

// approach 1st using set ( with O(n) complexity)
pair<int, string> LongestSubstring_1(string s)
{
    int len = s.length();
    unordered_set<char> charSet;
    int left = 0, maxlen = 0, start = 0;

    for (int right = 0; right < len; right++)
    {
        // if duplicate found, remove chars from left until duplicate is removed
        while (charSet.find(s[right]) != charSet.end())
        {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        if (right - left + 1 > maxlen)
        {
            maxlen = right - left + 1;
            start = left;
        }
    }
    return {maxlen, s.substr(start, maxlen)};
}

// with O(n) complexity using last index array
pair<int, string> LongestSubstring_2(string s)
{
    int len = s.length();
    vector<int> lastIndex(256, -1); // For all ASCII characters
    int left = 0, maxlen = 0, start = 0;

    for (int right = 0; right < len; right++)
    {
        char c = s[right];
        printf("\nStep %d: right=%d, char='%c'\n", right + 1, right, c);
        printf("  Window before: left=%d, right=%d, substring=\"%s\"\n", left, right, s.substr(left, right - left + 1).c_str());
        if (lastIndex[c] >= left)
        {
            printf("  '%c' was seen before at %d (inside window). Moving left to %d\n", c, lastIndex[c], lastIndex[c] + 1);
            left = lastIndex[c] + 1;
        }
        else
        {
            printf("  '%c' not seen in current window.\n", c);
        }
        lastIndex[c] = right;
        if (right - left + 1 > maxlen)
        {
            maxlen = right - left + 1;
            start = left;
            printf("  New maxlen=%d, start=%d\n", maxlen, start);
        }
        printf("  Window after: left=%d, right=%d, substring=\"%s\"\n", left, right, s.substr(left, right - left + 1).c_str());
    }
    return {maxlen, s.substr(start, maxlen)};
}

// approach 3rd using brute force ( with O(n^2) complexity)
pair<int, string> LongestSubstring_3(string s)
{
    int len = s.length();
    int left = 0, maxlen = 0, start = 0;

    for (int right = 0; right < len; right++)
    {
        char c = s[right];
        // If character was seen and is inside the current window, move left pointer
        for (int i = left; i < right; i++)
        {
            if (s[i] == c)
            {
                left = i + 1;
                break;
            }
        }
        if (right - left > maxlen)
        {
            maxlen = right - left + 1;
            start = left;
        }
    }
    return {maxlen, s.substr(start, maxlen)};
}

int main()
{
    string s = "abcastyybcsbb";
    auto result1 = LongestSubstring_1(s);
    cout << "Length of longest substring without repeating characters: " << result1.first << "\n";
    cout << "Longest substring without repeating characters: '" << result1.second << "'\n";

    auto result2 = LongestSubstring_2(s);
    cout << "Length of longest substring without repeating characters: " << result2.first << "\n";
    cout << "Longest substring without repeating characters: '" << result2.second << "'\n";

    auto result3 = LongestSubstring_3(s);
    cout << "Length of longest substring without repeating characters: " << result3.first << "\n";
    cout << "Longest substring without repeating characters: '" << result3.second << "'\n";
    return 0;
}