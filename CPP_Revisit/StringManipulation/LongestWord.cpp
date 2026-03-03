#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> findLongestWord(const string &str)
{
    vector<string> temp;
    if (str.empty())
        return temp;
    stringstream ss(str);
    string word;
    int maxlen = 0;

    while (ss >> word)
    {
        if (word.size() > maxlen)        
        {
            maxlen = word.size();
            temp.clear();
            temp.push_back(word);
        }
        else if (word.size() == maxlen)
        {
            temp.push_back(word);
        }
    }
    return temp;
}
int main()
{
    string text = "ab abc abcd";
    auto str = findLongestWord(text);
    if (!str.empty())
    {
        for (const auto &ch : str)
        {
            cout << " " << ch;
        }
    }
    cout << endl;
    // cout << " final: " << str << endl;
    return 0;
}