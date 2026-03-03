#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "aye ie aouh hueeyy";

    vector<char> vecChar;
    vector<int> vecIndex;
    int len = str.length() - 1;
    for (int i = 0; i <= len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vecChar.push_back(str[i]);
            vecIndex.push_back(i);
        }
    }

    sort(vecChar.begin(), vecChar.end(), greater<char>());
    for (int i = 0; i < vecIndex.size(); i++)
    {

        str[vecIndex[i]] = vecChar[i];
    }

    cout << "final string: " << str << endl;
    return 0;
}