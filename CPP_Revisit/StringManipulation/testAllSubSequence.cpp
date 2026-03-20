#include <iostream>
#include <unordered_set>

using namespace std;

void allSubSequence(const string &str)
{
    if (str.empty())
        return;

    int n = str.size();
    string temp = "";
    unordered_set<string> Set;
    for (int mask = 0; mask < (1LL << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1LL << i))
            {
                temp += str[i];
            }
        }
        Set.insert(temp);
        temp.clear();
    }
    for (const auto &ch : Set)
    {
        cout << ch << endl;
    }
}

int main()
{
    string str = "ABC";
    allSubSequence(str);
    return 0;
}