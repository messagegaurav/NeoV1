#include <bits/stdc++.h>

using namespace std;

int findPattern(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++)
    {
        if (text[i] == pattern[0])
        {
            int j = 0;
            while ((text[i + j] == pattern[j]) && j < m)
            {
                j++;
            }
            if (j == m)
            {
                cout << "Match found: " << i << "\n";
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    string text = "Baba Yaga is back in John wick now";
    string pattern;
    cout << "Enter Pattern: " << "\n";
    getline(cin, pattern);
    int pos = findPattern(text, pattern);
    if (pos != -1)
    {
        cout << "Pattern Found: " << pos << "\n";
    }
    else
    {
        cout << "Pattern Not Found..!!!" << "\n";
    }

    return 0;
}