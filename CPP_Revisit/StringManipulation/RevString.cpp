#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void revString(string &str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    // return str;
}

void usingLib(string &str)
{
    reverse(str.begin(), str.end());
}

string usingConstructor(string str)
{
    return string(str.rbegin(), str.rend());
}

int main()
{
    string text = "banana";
    revString(text);
    cout << "Reverse: " << text << endl;
    usingLib(text);
    cout << "original string: " << text << endl;
    auto str = usingConstructor(text);
    cout << "rev string: " << str << endl;
    return 0;
}