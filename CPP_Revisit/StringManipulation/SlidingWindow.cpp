#include <bits/stdc++.h>

using namespace std;

// using vector

pair<int, int> slidingWindowUsingVector(const string &text)
{
    int left = 0, right = 0;
    vector<char> vec;
    pair<int, int> indexRange;
    int len = text.length() - 1;
    int max = 0, tmp = 0;
    int tempLeft = 0, tempRight = 0;

    while (right <= len)
    {
        if (find(vec.begin(), vec.end(), text[right]) == vec.end())
        {
            cout << "val: " << text[right] << endl;
            vec.push_back(text[right]);
            for (auto &ch : vec)
            {
                cout << " " << ch << endl;
            }
            right++;
            // keep incrementing right
        }
        else
        {
            // cout << "in else now..." << endl;
            if (!vec.empty())
            {
                cout << "deleting left.." << endl;
                vec.erase(vec.begin());
                left++;
            }
            for (auto &ch : vec)
            {
                cout << " " << ch << endl;
            }
        }
        if (max < (right - left))
        {
            max = right - left;
            tempLeft = left;
            tempRight = right;
            cout << "Found max length pattern..." << max << endl;
        }
    }
    indexRange = make_pair(tempLeft, tempRight);
    return indexRange;
}

pair<int, int> usingSet(const string &text)
{
    int left = 0, right = 0;
    unordered_set<char> vec;
    pair<int, int> indexRange;
    int len = text.length() - 1;
    int max = 0, tmp = 0;
    int tempLeft = 0, tempRight = 0;

    while (right <= len)
    {
        if (!vec.count(text[right]))
        {
            cout << "val: " << text[right] << endl;
            vec.insert(text[right]);
            for (auto &ch : vec)
            {
                cout << " " << ch << endl;
            }
            right++;
            // keep incrementing right
        }
        else
        {
            // cout << "in else now..." << endl;
            if (!vec.empty())
            {
                cout << "deleting left.." << endl;
                vec.erase(text[left]);
                left++;
            }
            for (auto &ch : vec)
            {
                cout << " " << ch << endl;
            }
        }
        if (max < (right - left))
        {
            max = right - left;
            tempLeft = left;
            tempRight = right;
            cout << "Found max length pattern..." << max << endl;
        }
    }
    indexRange = make_pair(tempLeft, tempRight);
    return indexRange;
}
int main()
{
    string text = "abcdefga";
    // auto index = slidingWindowUsingVector(text);
    auto index = usingSet(text);
    cout << "final string: " << endl;
    for (int i = index.first; i < index.second; i++)
    {
        cout << " " << text[i];
    }
    cout << endl;
    return 0;
}