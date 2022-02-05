/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-02-05 21:50:09
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-02-06 00:56:09
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int atoi(string str)
{
    char *p;
    int num = 0, temp = 10, i = 0;
    bool flag = false;
    if (str[0] == '-')
    {
        flag = true;
        i++;
    }
    for (; i < str.length(); i++)
    {
        if (((str[i] - '0') >= 0) && ((str[i] - '0') <= 9))
        {
            num = num * temp + (str[i] - '0');
        }
        else
        {
            return -1;
        }
    }
    if (flag)
    {
        num = num * -1;
    }
    return num;
}

int main()
{
    string str = "-as197";
    int val = atoi(str);
    cout << "\n Val: " << val;

    return 0;
}