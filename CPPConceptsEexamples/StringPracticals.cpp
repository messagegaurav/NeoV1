/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-12 13:31:36
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-12 23:54:27
 */

#include <iostream>
#include <stack>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
void checkBrackets1stApproach(string &str);
void stringReverse(string &str);
bool checkParenthesis(const string &str);
int hellMatcherIfTwoWordsNearby(const vector<string> &str);

int main()
{
    /* Checking parenthesis starts */
    // string str;
    // getline(cin, str);

    // if (checkParenthesis(str))
    //     cout << "\n balanced ";
    // else
    //     cout << "\n not balanced ";

    /* Checking parenthesis ends */

    // string str;
    // getline(cin, str);

    // stringReverse(str);

    /* string reverse using stack */

    vector<string> myVec = {"tom", "jerry", "jerry", "tom"};
    int count = hellMatcherIfTwoWordsNearby(myVec);

    cout << "\n count: " << count;

    cout
        << "\n\n";
    return 0;
}

/* hell matcher starts */
int hellMatcherIfTwoWordsNearby(const vector<string> &str)
{
    stack<string> myStack;
    int flag = true;

    for (auto itr = str.begin(); itr != str.end(); itr++)
    {
        flag = true;
        if (!myStack.empty())
        {
            if (*itr == myStack.top())
            {
                myStack.pop();
                flag = false;
            }
        }
        if (flag)
            myStack.push(*itr);
    }
    int count = myStack.size();
    return count;
}
/* hell matcher ends */

// to check if parenthesis are proper or not :) yuppy.
bool checkParenthesis(const string &str)
{
    int len = str.length();
    stack<char> myStack;
    bool flag = true;

    for (int i = 0; i < len; i++)
    {
        if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']'))
        {
            if (myStack.empty())
            {
                cout << "\n Incorrect: no open brackets in stack...";
                flag = false;
                break;
            }
            else
            {
                switch (str[i])
                {
                case ')':
                    if (myStack.top() != '(')
                    {
                        cout << "\n not in correct order...";
                        flag = false;
                    }
                    else
                    {
                        cout << "\n bracket matched.. popping it out..";
                        flag = true;
                        myStack.pop();
                    }
                    break;
                case '}':
                    if (myStack.top() != '{')
                    {
                        cout << "\n not in correct order...";
                        flag = false;
                    }
                    else
                    {
                        cout << "\n bracket matched.. popping it out..";
                        flag = true;
                        myStack.pop();
                    }
                    break;

                case ']':
                    if (myStack.top() != '[')
                    {
                        cout << "\n not in correct order...";
                        flag = false;
                    }
                    else
                    {
                        cout << "\n bracket matched.. popping it out..";
                        flag = true;
                        myStack.pop();
                    }
                    break;
                }
            }
            if (!flag)
            {
                cout << "\n found the pattern is incorrect..";
                break;
            }
        }

        else if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
        {
            myStack.push(str[i]);
            flag = false;
        }
    }
    if (!myStack.empty())
    {
        flag = false;
    }
    return flag;
}

// line reversal using Stack starts
void stringReverse(string &str)
{
    int len = str.length();
    cout << "\n original len: " << len;
    stack<string> myStack;
    string temp = "";

    for (int i = 0; i < len; i++)
    {

        if (str[i] != ' ')
        {
            temp += str[i];
        }
        else
        {
            myStack.push(temp);
            temp = "";
        }
    }
    myStack.push(temp);
    temp = "";

    str = "";
    int i = 0;
    while (!myStack.empty())
    {
        str = str + " " + myStack.top();
        myStack.pop();
    }

    cout << "\n reverse string: " << str;
    cout << "\n length now: " << str.length();
}

// line reversal using stack ends

#if 0
void checkBrackets1stApproach(string &str)
{
    stack<char> myStack;
    int len = str.length();
    int i = 0;
    bool flag = true;
    while (i < len)
    {
        if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']'))
            myStack.push(str[i]);
        i++;
    }
    i = 0;
    while (i < len)
    {
        if (!myStack.empty())
        {
            switch (str[i])
            {
            case '(':
                if (myStack.top() != ')')
                {
                    flag = false;
                }
                else
                {
                    myStack.pop();
                }
                break;
            case '{':
                if (myStack.top() != '}')
                {
                    flag = false;
                }
                else
                {
                    myStack.pop();
                }
                break;
            case '[':
                if (myStack.top() != ']')
                {
                    flag = false;
                }
                else
                {
                    myStack.pop();
                }
                break;
            default:
                if ((str[i] == '}') || (str[i] == ']') || (str[i] == ')'))
                {
                    flag = false;
                }
                break;
            }
            if (!flag)
                break;
        }
        else if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
        {
            flag = false;
            break;
        }
        i++;
    }

    if (flag)
    {
        cout << "\n\n Parenthesis matches..";
    }
    else
    {
        cout << "\n incorrect use of parenthesis...";
    }
}
#endif