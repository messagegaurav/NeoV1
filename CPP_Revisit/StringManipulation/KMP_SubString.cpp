#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPS(const string &pattern)
{
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int KMPSearch(const string &text, const string &pattern)
{
    vector<int> LPS = computeLPS(pattern);

    int n = text.length();
    int m = pattern.length();

    int j = 0;
    int i = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            int pos = i - m;
            cout << "Pattern found at: " << pos << "\n";
            return pos;
        }
        else if ((i < n) && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return -1;
}

int main()
{
    string str = "AABCAAADFGAFAAAP";
    string pattern;
    cout << "Enter pattern: ";
    getline(cin, pattern);

    int pos = KMPSearch(str, pattern);
    if (pos != -1)
    {
        cout << "Pattern found at: " << pos << "\n";
    }
    else
    {
        cout << "Pattern not found.. !!!!" << "\n";
    }

    return 0;
}
