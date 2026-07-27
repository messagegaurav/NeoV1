#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

// using Map
bool validAnagram(std::string str1, std::string str2)
{

    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 != len2)
        std::cout << "Not a valid anagram !!!" << "\n";
    std::unordered_map<char, int> Map;
    for (auto &ch : str1)
    {
        Map[ch]++;
    }
    int right = 0;
    while (right < len2)
    {
        if (Map.count(str2[right]) > 0)
        {
            Map[str2[right]]--;
        }
        else
        {
            return false;
        }
        right++;
    }
    return true;
}

bool usingFreqArray(std::string str1, std::string str2)
{
    std::vector<int> freq(256, 0);
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 != len2)
        return false;

    for (auto &ch : str1)
    {
        freq[ch]++;
    }

    for (auto &ch : str2)
    {
        if (freq[ch] > 0)
        {
            freq[ch]--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string str1 = "near";
    std::string str2 = "earn";

    // auto result = validAnagram(str1, str2);
    auto result = usingFreqArray(str1, str2);
    std::cout << (result ? "Valid Anagram !!!" : "Not a valid Anagram") << "\n";
    return 0;
}
// using set or any STL
// using frequency array
