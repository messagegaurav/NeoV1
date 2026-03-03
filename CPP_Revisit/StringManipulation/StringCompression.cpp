#include <bits/stdc++.h>

using namespace std;

string usingMap(const string &text)
{
    map<char, int> mMap;
    string str;

    for (auto &ch : text)
    {
        mMap[ch]++;
    }
    for (auto &ch : mMap)
    {
        str += ch.first;
        if (ch.first != ' ')
            str += to_string(ch.second);
    }
    return str;
}

string usingRegApproach(const string &str)
{
    if (str.empty())
        return "";

    string temp = "";
    int count = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (i + 1 < str.length() && str[i] == str[i + 1])
        {
            count++;
        }
        else
        {
            temp += str[i];
            temp += to_string(count);
            count = 1;
        }
    }
    return temp;
}

int main()
{
    string text = "aaabbc";
    auto str = usingMap(text);
    cout << "compressed string is: " << str << endl;
    auto str1 = usingRegApproach(text);
    cout << "compressed string is: " << str1 << endl;
    return 0;
}