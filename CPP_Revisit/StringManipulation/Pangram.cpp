#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isPangram(const string &str)
{
    vector<int> freq(26, 0);
    for (const auto &ch : str)
    {
        if (isalpha(ch))
        {
            freq[tolower(ch) - 'a']++;
        }
    }
    for (const auto &ch : freq)
    {
        if (ch == 0)
            return false;
    }
    return true;
}

int main()
{
    string text = " The quick brown fox jumps over the lazy dog";
    cout << (isPangram(text) ? "Pangram" : "Not Pangram") << endl;
    return 0;
}