/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-04 00:06:51
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-04 00:41:46
 */

#include <iostream>
#include <string.h>

using namespace std;

class friendBase;

class base
{
    int data;

public:
    void printVal()
    {
        cout << "\n data: " << data;
    }
    friend void setData(base &b, int _data);

    friend class friendBase;
};

class friendBase
{
public:
    int getData(base &b)
    {
        return b.data;
    }
};

void setData(base &b, int _data)
{
    b.data = _data;
}

int main()
{
    base b1;
    setData(b1, 20);
    b1.printVal();
    friendBase f1;

    cout << "\n friend accessing: " << f1.getData(b1);

    cout << "\n\n";
    return 0;
}
