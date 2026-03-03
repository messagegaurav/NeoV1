#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkDigit(const string &str)
{
    return all_of(str.begin(), str.end(), ::isdigit);
}

int countDigit(const string &str)
{
    return count_if(str.begin(), str.end(), ::isdigit);
}

string getDigits(const string &str)
{
    string result;
    copy_if(str.begin(), str.end(), back_inserter(result), ::isdigit);
    return result;
}
int main()
{
    string text = "a21v1b3";
    cout << (checkDigit(text) ? "Yes Digits threre" : "No digits there") << endl;
    auto ptr = countDigit(text);
    cout << "total digits are: " << ptr << endl;

    auto str = getDigits(text);
    cout << " digits are: " << str << endl;
    return 0;
}