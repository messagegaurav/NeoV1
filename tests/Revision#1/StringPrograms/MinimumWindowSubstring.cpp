/* problem statement: input1 : AABCDEAFGH & input2 = FAG then output = AFG */
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <climits>

/* below function is good only if we have to check whether target string exists in source string or not thats it.. !!!*/
// int findingIfMinWinSubStringExists()
// {
//     std::string text1 = "AABCDEAFGH";
//     std::string text2 = "FAG";
//     std::map<char, int> Map;
//     for (auto &ch : text2)
//     {
//         Map[ch]++;
//     }

//     int i = 0;
//     int left = 0, right = 0;
//     while (right < text1.size())
//     {
//         int check = 0;
//         if (Map.find(text1[right]) != Map.end())
//         {
//             left = right;
//             while (Map.find(text1[right]) != Map.end())
//             {
//                 if (Map[text1[right]] > 1)
//                 {
//                     Map[text1[right]]--;
//                 }
//                 else
//                 {
//                     Map.erase(text1[right]);
//                 }
//                 check++;
//                 right++;
//             }
//             if (check == text2.size())
//             {
//                 std::cout << "final string: " << text1.substr(left, right - left) << "\n";
//                 return 0;
//             }
//         }
//         Map.clear();
//         for (auto &ch : text2)
//         {
//             Map[ch]++;
//         }
//         right++;
//     }
//     std::cout << "No MWS found !!!" << "\n";
// }

std::string findMinWinSubString(std::string source, std::string target)
{
    if (source.empty() || target.empty())
    {
        std::cout << "String is empty... !!!" << "\n";
        return "";
    }

    if (target.size() > source.size())
    {
        std::cout << "Invalid Target Size.. !!!" << "\n";
        return "";
    }

    int right = 0, left = 0, minWin = INT_MAX, start = 0;
    int tSize = target.size();
    int sSize = source.size();
    std::unordered_map<char, int> need, window;
    int valid = 0;

    for (auto &ch : target)
    {
        need[ch]++;
    }

    while (right < sSize)
    {
        char c = source[right];
        window[c]++;
        if (need.count(c) && window[c] == need[c])
        {
            valid++;
        }
        while (valid == need.size())
        {
            if (minWin > right - left)
            {
                minWin = right - left + 1;
                start = left;
            }
            char d = source[left];
            if (need.count(d) && window[d] == need[d])
            {
                valid--;
            }
            window[d]--;
            left++;
        }
        right++;
    }
    return (minWin == INT_MAX) ? "" : source.substr(start, minWin);
}

int main()
{
    std::string source = "AABCDEAFGH";
    std::string target = "FAG";
    std::cout << "final result is: " << findMinWinSubString(source, target) << "\n";

    return 0;
}