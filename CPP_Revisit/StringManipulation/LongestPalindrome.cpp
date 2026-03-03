#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string findLongestPal(const string &text)
{
    if (text.empty())
        return "";
    int n = text.size();
    if (n <= 1)
        return text;
    int start = 0, maxlen = 1;
    auto expand = [&](int left, int right)
    {
        while ((left >= 0 && right < n) && (text[left] == text[right]))
        {
            left--;
            right++;
        }
        int currLen = right - left - 1;
        if (currLen > maxlen)
        {
            maxlen = currLen;
            start = left + 1;
        }
    };

    for (int i = 0; i < n; i++)
    {
        expand(i, i);     // for odd
        expand(i, i + 1); // for even
    }

    return text.substr(start, maxlen);
}

int main()
{
    string text = "racecar";
    auto str = findLongestPal(text);
    cout << "final string: " << str << endl;
    return 0;
}
