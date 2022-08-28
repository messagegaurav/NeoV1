/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-23 02:38:36
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-23 15:29:01
 */

#include <iostream>
#include <stdio.h>
#include <bitset>

using namespace std;

int main()
{
    int num = 8;
    cout << "\n binary value of " << num << " is: " << bitset<16>(num);

    // check if num is even or odd
    if (num & 1)
        cout << "\n num: " << num << " is odd";
    else
        cout << "\n num: " << num << " is even";

    // to increment the num by 1
    int k = -~num; // 2's complement + 1;
    cout << "\n incremented num by 1: " << k;

    // turn off Kth bit in a number
    k = 10;

    cout << " \n before turning off num: " << bitset<16>(num);

    num = (num ^ (1 << (k - 1)));

    cout << "\n after turning it off num: " << bitset<16>(num);

    // turning on Kth bit
    k = 11;

    num = (num | (1 << (k - 1)));

    cout << "\n after turning it ON num: " << bitset<16>(num);

    // checking if kth bit is set or not

    if (num & (1 << (k - 1)))
        cout << "\n kth position is already ON..";
    else
        cout << "\n kth position bit is OFF..";

    // toggling the kth bit
    num = (num ^ (1 << (k - 1)));
    cout << "\n kth bit has been toggled... " << bitset<16>(num);

    // find the rightmost set bit
    num = num ^ (num & (num - 1));

    k = 0;
    while (num)
    {
        num = num >> 1;
        k++;
    }

    cout << "\n position of rightmost set bit: " << k;

    num = 8;
    k = 0;
    int temp = 0;
    // find the only set bit position in the num
    if (num & (num - 1))
    {
        cout << "\n more than one set are there..";
    }
    else
    {
        temp = num;
        while (temp)
        {
            temp = temp >> 1;
            k++;
        }
        cout << "\n only set bit position: " << k << " for num: " << bitset<16>(num);
    }

    // find the parity of the number
    num = 7;
    temp = num;
    int parity = 0;
    while (temp)
    {
        temp = temp >> 1;
        parity++;
    }
    if (parity % 2)
        cout << "\n num is having odd parity..";
    else
        cout << "\n num is having even parity..";

    // checking endianess
    int no = 0x01234567;
    char *p = (char *)&no;

    int i = 0;
    cout << "\n checking the endianness...";
    while (i < sizeof(no))
    {
        printf(" %.2x", p[i]);
        printf("\n");
        i++;
    }

    // alternate solution
    no = 1;
    p = (char *)&no;
    if (*p)
    {
        cout << "\n little endian....";
    }
    else
        cout << "\n big endian...";

    cout << "\n\n";
    return 0;
}
