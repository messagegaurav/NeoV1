#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// minimum window substring is like extracting minimum contiguous seq from main string
// that has all the char in the given target string

using namespace std;

/* base approach */
// string minWindowSubstring(string source, string target)
// {
//     // keep target string in a set
//     // while going through main string if char matches, remove that char from targetSet
//     // if everything is removed, and minlen achieved send that minlen substring

//     int targetLen = target.size();
//     int sourceLen = source.size();

//     if (targetLen > sourceLen)
//         return "";

//     if (targetLen == 0)
//         return source;

//     int left = 0, right = 0;
//     int minlen = 0, start = 0;

//     unordered_set<char> targetSet;

//     for (auto &ch : target)
//         targetSet.insert(ch);

//     unordered_set<char> temp;
//     temp = targetSet;

//     while (right < sourceLen)
//     {
//         // if first char found
//         // go in while loop, until the remaining length
//         // check if target set is exhausted - match found assign minlen
//         // assign temp with target Set and do the same thing again

//         if (temp.count(source[right]) > 0)
//         {
//             temp.erase(source[right]);
//             left = right;
//             int tempRight = right;
//             while ((tempRight < sourceLen) && !temp.empty())
//             {
//                 if (temp.count(source[tempRight]) > 0)
//                 {
//                     temp.erase(source[tempRight]);
//                 }
//                 tempRight++;
//             }
//             if (temp.empty())
//             {
//                 if (minlen == 0)
//                 {
//                     minlen = tempRight - left;
//                 }
//                 else if (tempRight - left < minlen)
//                 {
//                     minlen = tempRight - left;
//                     start = left;
//                 }
//             }
//             temp = targetSet;
//         }
//         right++;
//     }
//     return source.substr(start, minlen);
// }

/* using unordered_map approach*/

string smartWindowSubString(string source, string text)
{
    if (source.empty() || text.empty() || text.size() > source.size())
        return "";
    unordered_map<char, int> target;
    unordered_map<char, int> window;
    int count = 0;
    bool valid = false;

    for (auto const &ch : text)
        target[ch]++;

    int left = 0, right = 0;
    int len = source.size();

    while (right < len)
    {
        if (target[right] > 0)
        {
            if (target[right] == window[right])
            {
                count++;
                if (count == len)
                    valid = true;
            }
        }
    }
}

int main()
{
    string source = "abdghaczgiabc";
    string target = "cga";
    // cout << "Min window substring : " << minWindowSubstring(source, target) << "\n";
    cout << "Min window substring : " << smartWindowSubString(source, target) << "\n";
    return 0;
}