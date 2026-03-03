#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

string findMinSeq(const string &source, const string &target)
{
    if (target.size() > source.size())
        return "";
    vector<int> vec_need(128, 0);

    for (auto &ch : target)
    {
        vec_need[ch]++;
    }

    int req = target.size();

    int left = 0, right = 0;
    int start = 0, minlen = INT_MAX;
    int len = source.size();
    for (; right < len; right++)
    {
        if (vec_need[source[right]] > 0)
        {
            req--;
        }
        vec_need[source[right]]--;

        while (req == 0)
        {
            if (right - left + 1 < minlen)
            {
                minlen = right - left + 1;
                start = left;
            }

            vec_need[source[left]]++;
            if (vec_need[source[left]] > 0)
            {
                req++;
            }
            left++;
        }
    }
    return minlen == INT_MAX ? "" : source.substr(start, minlen);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum Window Substring: " << findMinSeq(s, t) << endl;
    return 0;
}