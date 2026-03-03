#include <bits/stdc++.h>

using namespace std;

int repeatingChar(const string &str)
{
    unordered_map<char, int> umap;
    for (auto &ch : str)
    {
        umap[ch]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (umap[str[i]] > 1)
        {
            return i;
        }
    }
    return -1;
}

char usingVector(const string &str)
{
    vector<int> vec(256, 0);
    for (auto &ch : str)
    {
        vec[ch]++;
    }

    for (auto &ch : str)
    {
        if (vec[ch] > 1)
            return ch;
    }
    return '\0';
}

int main()
{
    string str = "hola bola";
    // int pos = repeatingChar(str);
    auto pos = usingVector(str);
    cout << "first repeating char: " << pos << endl;
    // if (pos != -1)
    // {
    //     cout << "First Repeating char at: " << pos << endl;
    // }
    // else
    // {
    //     cout << "No repeating char found.. !!!!" << endl;
    // }
    return 0;
}
