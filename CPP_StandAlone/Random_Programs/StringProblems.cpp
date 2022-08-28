/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-02-01 22:06:43
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-02-02 02:13:01
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

// reversing a string
void reverse_String(string &ptr)
{
    char ch;
    int i = 0, j = ptr.length() - 1;

    if (j <= 0)
    {
        cout << "\n no string provided..";
        return;
    }
    for (; i <= j; i++, j--)
    {
        ch = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = ch;
    }
}

void count_Vowels(string &str)
{
    int j = str.length() - 1;
    int a(0), i(0), e(0), o(0), u(0);

    for (int it = 0; it < j; it++)
    {
        switch (str[it])
        {
        case 'a':
            a++;
            break;
        case 'i':
            i++;
            break;
        case 'e':
            e++;
            break;
        case 'o':
            o++;
            break;
        case 'u':
            u++;
            break;
        default:
            break;
        }
    }
    cout << "\n       a:  " << a << " e:  " << e << " i:  " << i << " o:  " << o << "     u: " << u;
}

// never assign {0} to a string instead assing "" otherwise it will already add a NULL to it.
string reverseWords(string S)
{
    map<int, string> myMap;
    string str;
    int j = S.length();
    int count(0);
    char ch;
    for (int i = 0; i < j; i++)
    {
        if (S[i] == '.')
        {
            myMap.insert({count, str});
            count++;
            str = "";
        }
        else
        {
            ch = S[i];
            str = str + ch;
        }
    }

    myMap.insert({count, str});
    S = "";
    for (auto itr = myMap.rbegin(); itr != myMap.rend(); itr++)
    {
        S = S + itr->second.c_str();
        if (count > 0)
        {
            count--;
            S = S + '.';
        }
    }
    return S;
}

int main()
{
    string str;
    cout << "\n enter the string...\n:";
    getline(cin, str);

    // reverse_String(str);
    // cout << "\n reversed string...";
    // cout << "\n " << str;

    // count_Vowels(str);

    string ptr = reverseWords(str);
    cout << "\n reversed words of string....";
    cout << "\n:" << ptr;
    cout << "\n size: " << ptr.length();

    if (ptr == "much.very.program.this.like.i")
    {
        cout << "\n pass";
    }

    cout << "\n\n";
    return 0;
}