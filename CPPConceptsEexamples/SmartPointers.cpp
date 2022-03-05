/*
 * Created on Thu Jan 20 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <string.h>

using namespace std;

class based
{
public:
    int fun(int a) const
    {
        return a * 2;
    }
    based()
    {
    }

private:
    char a[20];
};

int main()
{
    based b1;
    int a = b1.fun(10);
    cout << "\n val: " << a;
    cout << "\n\n";
    return 0;
}