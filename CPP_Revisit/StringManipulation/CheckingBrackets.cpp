#include <bits/stdc++.h>

using namespace std;

bool checkBrackets(const string &str)
{
    // insert all open brackets into stack
    // if you encounter any close bracket, pop out stack and see if its fine
    stack<char> staq;
    for (auto &ch : str)
    {
        if (ch == '[' || ch == '{' || ch == '(')
        {
            staq.push(ch);
        }

        if ((ch == ']') || (ch == '}') || (ch == ')'))
        {
            if (staq.empty())
                return false;
            else if ((ch == ']' && staq.top() == '[') ||
                     (ch == '}' && staq.top() == '{') ||
                     (ch == ')' && staq.top() == '('))
            {
                staq.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return staq.empty();
}

int main()
{
    string text = "abc*{ab(*[d])}";
    cout << (checkBrackets(text) ? "Yes, its even brackets" : "incomplete brackets");
    cout << "\n";
}