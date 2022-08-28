/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-23 14:53:43
 * @Last Modified by:   gaurav
 * @Last Modified time: 2022-04-23 14:53:43
 */

#include "mychrono.h"
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>


Chrono myClock;

int getNext(int n)
{
    int total = 0;
    while (n > 0)
    {
        total += ((n % 10) * (n % 10));
        n = n / 10;
    }
    return total;
}

bool isHappy(int n) {

    int slow, fast;
    slow = n;
    fast = getNext(n);

    while ((fast != 1) && (slow != fast))
    {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    if (fast == 1)
        return true;
    else
        return false;
}

int main()
{
    int num;
    cout << "\n enter the num: ";
    cin >> num;
    isHappy(num) ? cout << "\n Yeyy its a happy number..." : cout << "\n Noo its not a happy number...";
    cout << endl;
    return 0;
}








