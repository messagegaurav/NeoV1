#include <bits/stdc++.h>

using namespace std;

string removeSpaces(const string &str)
{
    if (str.empty())
        return "";
    string temp;
    stringstream ss(str);
    string word;
    while (ss >> word)
    {
        temp += word;
        // temp += " ";
    }
    return temp;
}

string useVector(const string &str)
{
    string temp;
    vector<string> myvec;
    if (str.empty())
        return "";
    for (auto &ch : str)
    {
        if (tolower(ch) >= 'a' && tolower(ch) <= 'z')
        {
            temp += ch;
        }
        else
        {
            myvec.push_back(temp);
            temp = " ";
        }
    }
    myvec.push_back(temp);
    reverse(myvec.begin(), myvec.end());
    temp = "";
    for (auto &ch : myvec)
    {
        // temp += ch;
        cout << " " << ch;
    }
    return temp;
}

int main()
{
    string text;
    cout << "Enter string: " << text;
    getline(cin, text);
    // auto str = removeSpaces(text);
    auto str = useVector(text);
    cout << "Final: " << str << endl;
    return 0;
}