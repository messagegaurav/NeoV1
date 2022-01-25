/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-24 14:00:55
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-24 14:15:40
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

#pragma pack(1)

using namespace std;

struct base
{
    char a;
    int b;
    double c;
};
// } __attribute__((packed));

int main()
{
    base b;
    cout << "\n struct size: " << sizeof(b);

    cout << "\n\n";
    return 0;
}