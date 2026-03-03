#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool checkRotation(const string &str, const string &str1)
{
    if ((str.length() != str1.length()) || str.empty())
        return false;

    string temp = str + str;
    if (temp.find(str1) != string::npos)
        return true;
    else
        return false;
}

int main()
{
    string text = "AADC";
    string pattern = "DCAA";

    cout << (checkRotation(text, pattern) ? "Yes Rotation" : "No Rotation") << endl;
    return 0;
}