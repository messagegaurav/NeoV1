#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string LCS(const string &s1, const string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    } // LCS table constructed

    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    string lcs = LCS(s1, s2);

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length: " << lcs.size() << endl;

    return 0;
}
