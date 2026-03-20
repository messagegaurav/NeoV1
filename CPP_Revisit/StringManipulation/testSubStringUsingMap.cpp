#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Using substr
// void usingSubstr(const string &str, const string &pattern)
// {
//     int len = str.size();
//     int pLen = pattern.size();
//     for (int i = 0; i < len - pLen; i++)
//     {
//         if (str.substr(i, pLen) == pattern)
//             cout << "Pattern found at index: " << i << endl;
//     }
// }

// Function to build LPS array
vector<int> buildLps(const string &pattern)
{
    int n = pattern.size();
    int i = 1;
    int len = 0; // lps len
    vector<int> lps(n, 0);

    while (i < n)
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
                len = lps[len - 1]; // fallback
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

void KMPSearch(const string &text, const string &pattern)
{
    int m = text.size();
    int n = pattern.size();
    if (n > m)
        return;

    vector<int> lps = buildLps(pattern);
    int i = 0, j = 0;
    while (i < m)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else if (j == n)
        {
            cout << "Found pattern starting at: " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < m && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1]; // fallback
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    string str = "AACDBADDCDBJJ";
    string pattern = "CDB";

    // usingSubstr(str, pattern);
    KMPSearch(str, pattern);
    cout << endl;
    return 0;
}