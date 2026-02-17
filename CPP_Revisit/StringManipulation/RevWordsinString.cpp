#include <bits/stdc++.h>

using namespace std;

void revString(const string &text)
{
    stack<string> staq;
    // vector<string> vec;
    string str;
    for (auto &ch : text)
    {
        if ((ch >= 'a' || ch >= 'A') && (ch <= 'z' || ch <= 'Z'))
        {
            str += ch;
        }
        else
        {
            staq.push(str);
            // vec.push_back(str);
            str = " ";
        }
    }
    staq.push(str);
    // vec.push_back(str);
    while (!staq.empty())
    {
        cout << " " << staq.top();
        staq.pop();
    }
    // reverse(vec.begin(), vec.end());
    // for (auto &ch : vec)
    // {
    //     cout << " " << ch;
    // }
}
int main()
{
    string str = "Baba Yaga is back in John wick";
    revString(str);
    cout << "\n";
    return 0;
}