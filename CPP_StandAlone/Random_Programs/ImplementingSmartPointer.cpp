/*
 * Created on Thu Jan 20 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <string.h>

using namespace std;

template <class T>
class SmartPtr
{
private:
    T *ptr;

public:
    explicit SmartPtr(T *p = NULL)
    {
        ptr = p;
        cout << "\n constructed..";
    }

    ~SmartPtr()
    {
        delete (ptr);
        cout << "\n destructed";
    }

    T &operator*() { return *ptr; }

    T &operator->() { return *ptr; }
};

int main()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << "\n val: " << *ptr;
    return 0;
}
