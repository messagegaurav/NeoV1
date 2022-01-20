/*
 * Created on Thu Jan 20 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

class base
{
public:
    base()
    {
        cout << "\n constructed base";
    }
    void fun()
    {
        cout << "\n I am doin fun";
    }
    ~base()
    {
        cout << "\n base destructed";
    }
};

class derived : public base
{

public:
    derived()
    {
        cout << "\n derived constructed";
    }

    void fun()
    {
        cout << "\n doin fun in derived";
    }
    ~derived()
    {
        cout << "\n derived destructed";
    }
};

int main()
{
    base b1;
    b1.fun();

    // derived *d = new derived();
    // d->fun();

    derived d1;
    d1.fun();

    return 0;
}
