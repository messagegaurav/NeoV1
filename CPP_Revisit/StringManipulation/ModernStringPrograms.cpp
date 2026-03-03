1. Pattern Matching(KMP Algorithm)
    The key to KMP is the LPS(Longest Prefix Suffix) array,
    which allows us to skip characters we've already matched.

    C++
#include <iostream>
#include <vector>
#include <string>

    // Function to compute the LPS array
    void computeLPS(std::string pat, std::vector<int> &lps)
{
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < pat.length())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search: O(N + M)
void KMPSearch(std::string txt, std::string pat)
{
    int M = pat.length(), N = txt.length();
    std::vector<int> lps(M);
    computeLPS(pat, lps);

    int i = 0, j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            std::cout << "Pattern found at index " << i - j << std::endl;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

2. Optimization(Sliding Window)
    Problem : Longest Substring Without Repeating Characters.

              C++
#include <unordered_map>
#include <algorithm>

              int lengthOfLongestSubstring(std::string s)
{
    std::vector<int> m(256, -1); // Map char to its last seen index
    int left = 0, right = 0, res = 0;
    int n = s.length();

    while (right < n)
    {
        if (m[s[right]] != -1)
            left = std::max(left, m[s[right]] + 1);

        m[s[right]] = right;
        res = std::max(res, right - left + 1);
        right++;
    }
    return res;
}

3. Palindromes(Expand Around Center)
    Problem : Longest Palindromic Substring.

              C++ std::string longestPalindrome(std::string s)
{
    if (s.length() < 1)
        return "";
    int start = 0, end = 0;

    for (int i = 0; i < s.length(); i++)
    {
        auto expand = [&](int l, int r)
        {
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                l--;
                r++;
            }
            return r - l - 1;
        };

        int len1 = expand(i, i);     // Odd length (aba)
        int len2 = expand(i, i + 1); // Even length (abba)
        int len = std::max(len1, len2);

        if (len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}

4. Transformation(atoi)
        Problem : Implement myAtoi to convert a string to a 32 -
                  bit signed integer.

                  C++
#include <climits>

                  int myAtoi(std::string s)
{
    int i = 0, sign = 1, res = 0;
    while (s[i] == ' ')
        i++; // Skip whitespace

    if (s[i] == '-' || s[i] == '+')
    {
        sign = (s[i++] == '-') ? -1 : 1;
    }

    while (i < s.length() && isdigit(s[i]))
    {
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > 7))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        res = res * 10 + (s[i++] - '0');
    }
    return res * sign;
}

5. Prefixes(Trie Implementation)
    Problem : Implement a Trie(Prefix Tree)
                  .

              C++ class TrieNode
{
public:
    TrieNode *children[26] = {nullptr};
    bool isEnd = false;
};

class Trie
{
    TrieNode *root;

public:
    Trie() { root = new TrieNode(); }

    void insert(std::string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }

    bool search(std::string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (!curr->children[c - 'a'])
                return false;
            curr = curr->children[c - 'a'];
        }
        return curr->isEnd;
    }
};

6. Dynamic Programming(Edit Distance) Problem : Find the minimum number of operations(insert, delete, replace)
required to convert word1 to word2.C++ #include<vector>
#include <string>
#include <algorithm>

    int minDistance(std::string word1, std::string word2)
{
    int m = word1.length();
    int n = word2.length();

    // dp[i][j] stores the edit distance between word1[0...i-1] and word2[0...j-1]
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // If first string is empty, we must insert all characters of second string
            if (i == 0)
                dp[i][j] = j;

            // If second string is empty, we must delete all characters of first string
            else if (j == 0)
                dp[i][j] = i;

            // If characters match, ignore last char and recurse for remaining
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If characters don't match, consider all three operations
            else
            {
                dp[i][j] = 1 + std::min({
                                   dp[i][j - 1],    // Insert
                                   dp[i - 1][j],    // Remove
                                   dp[i - 1][j - 1] // Replace
                               });
            }
        }
    }
    return dp[m][n];
}

7. Palindrome Partitioning(Backtracking) Problem : Partition a string such that every substring of the partition is a palindrome.C++ #include<vector>
#include <string>

                                                   bool isPalindrome(std::string s, int low, int high)
{
    while (low < high)
    {
        if (s[low++] != s[high--])
            return false;
    }
    return true;
}

void backtrack(std::string s, int start, std::vector<std::string> &path, std::vector<std::vector<std::string>> &res)
{
    if (start == s.length())
    {
        res.push_back(path);
        return;
    }
    for (int end = start; end < s.length(); end++)
    {
        if (isPalindrome(s, start, end))
        {
            path.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, path, res);
            path.pop_back(); // Backtrack
        }
    }
}

std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> path;
    backtrack(s, 0, path, res);
    return res;
}
