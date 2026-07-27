#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>

// using unordered_set with two pointers approach
std::string usingSet(std::string &str)
{
    int len = str.size();
    int right = 0, left = 0;
    int maxlen = 0, start = 0;

    std::unordered_set<char> match;
    while (right < len)
    {
        if (match.find(str[right]) != match.end())
        {
            while (match.find(str[right]) != match.end())
            {
                match.erase(str[left]);
                left++;
            }
        }
        match.insert(str[right]);
        right++;
        if (maxlen < right - left)
        {
            maxlen = right - left;
            start = left;
        }
    }

    return str.substr(start, maxlen);
}

// using frequency array now
std::string usingFreqArray(std::string &str)
{
    std::vector<int> freq(256, 0);
    int len = str.size();
    int right = 0, left = 0;
    int maxlen = 0, start = 0;
    while (right < len)
    {
        if (freq[str[right]] > 0)
        {
            while (freq[str[right]] > 0)
            {
                freq[str[left]]--;
                left++;
            }
        }

        freq[str[right]]++;
        right++;
        if (maxlen < right - left)
        {
            maxlen = right - left;
            start = left;
        }
    }
    return str.substr(start, maxlen);
}

int main()
{
    std::string str = "pwwkew";
    auto final = usingSet(str);
    auto final1 = usingFreqArray(str);
    std::cout << "final string is:  " << final << "\n";
    std::cout << "final string is:  " << final1 << "\n";
    std::cout << "\n";
    return 0;
}