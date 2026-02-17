#include <bits/stdc++.h>

using namespace std;

// using the built in library function
bool palindromeCheck(const string &text)
{
    string temp;
    temp = text;
    reverse(temp.begin(), temp.end());
    return temp == text;
}

bool checkUsingStack(const string &text)
{
    stack<char> stack;
    for (auto &ch : text)
    {
        stack.push(ch);
    }

    for (auto &ch : text)
    {
        if (ch == stack.top())
        {
            stack.pop();
        }
        else
            return false;
    }
    return true;
}

bool usingTwoPointers(const string &text)
{
    int left = 0;
    int right = text.length() - 1;
    bool flag = true;
    while (text[left] != text[right])
    {
        flag = false;
    }
    return flag;
}

int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    bool check = palindromeCheck(str);
    cout << ((check) ? "Yes its a Palindrome text" : "No its not a palindrome Text");
    check = checkUsingStack(str);
    cout << ((check) ? "Yes its a Palindrome text" : "No its not a palindrome Text");
    check = usingTwoPointers(str);
    cout << ((check) ? "Yes its a Palindrome text" : "No its not a palindrome Text");
    cout << "\n";
    return 0;
}