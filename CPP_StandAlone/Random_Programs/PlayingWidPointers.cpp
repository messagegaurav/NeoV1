/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-28 09:45:25
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-28 10:12:51
 */

#include <iostream>
#include <string.h>

using namespace std;

int *wow()
{
    int i = 10;
    // int* p = &i;
    int *p = new int;
    *p = i;
    return p;
}

class base
{
    char *ptr;
    int length;

public:
    void printVal()
    {
        cout << "\n string is: " << ptr << " lenght is: " << length;
    }

    base()
    {
        cout << "\n calling default ctr...";
    };

    void setData(const char *ptr, int len)
    {
        this->length = len;
        this->ptr = new char[len];
        strncpy(this->ptr, ptr, len);
    }
    base(const base &b1)
    {
        cout << "\n calling copy ctr..";
        this->length = b1.length;
        this->ptr = new char[length];
        strncpy(this->ptr, b1.ptr, this->length);
    }
    base &operator=(const base &b1)
    {
        if (this != &b1)
        {
            cout << "\n calling assignment ctr..";
            delete this->ptr;
            this->length = b1.length;
            this->ptr = new char[this->length];
            strncpy(this->ptr, b1.ptr, this->length);
        }
        return *this;
    }

    base(base &&b1)
    {
        cout << "\n calling move ctr...";
        if (this != &b1)
        {
            this->length = b1.length;
            this->ptr = b1.ptr;
        }
        b1.length = 0;
        b1.ptr = nullptr;
    }

    base &operator=(base &&b1)
    {
        if (this != &b1)
        {
            cout << "\n calling move assignment ctr..";
            this->length = b1.length;
            this->ptr = b1.ptr;
        }
        b1.length = 0;
        b1.ptr = nullptr;
        return *this;
    }

    ~base()
    {
        cout << "\n calling destructor... ";
        delete[] ptr;
    }
};

int main()
{
    // int *ptr = wow();
    // cout << "\n val: " << *ptr;
    // delete ptr;

    base b1;
    b1.setData("gaurav", 6);
    b1.printVal();

    base b2(b1);
    b2.printVal();

    b1 = b2;
    b1.printVal();

    base b3(move(b2));
    b3.printVal();

    base b4;
    b4 = move(b3);
    b4.printVal();

    cout << "\n\n";
    return 0;
}