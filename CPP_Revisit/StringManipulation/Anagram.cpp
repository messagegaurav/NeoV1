#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool usingFreqArray(const string &str, const string &str1)
{

    if (str.length() != str1.length()) // Add this check
        return false;
    vector<int> freq(256, 0);
    for (auto &ch : str)
    {
        freq[ch]++;
    }

    for (auto &ch : str1)
    {
        freq[ch]--;
        if (freq[ch] < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str = "hola bola";
    string str2 = "bola hola";
    unordered_map<char, int> mmap1;
    unordered_map<char, int> mmap2;

    for (auto &ch : str)
    {
        mmap1[ch]++;
    }
    for (auto &ch : str2)
    {
        mmap2[ch]++;
    }

    if (mmap1 == mmap2)
    {
        cout << "Anagram" << endl;
    }
    else
    {
        cout << "Not an Anagram" << endl;
    }
    cout << endl;
    cout << "String is: " << (usingFreqArray(str, str2) ? "Anagram" : "Not Anagram") << endl;
    return 0;
}