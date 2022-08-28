/*
 * Created on Thu Jan 20 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// Three ways:
// 1. Using final keyword best one.
// 2. Declare all the constructor private and define a static method to return new objects.
// 3. Will discuss third method using virtual inheritance here.

class Unique;
class StopInheritance
{
public:
    ~StopInheritance()
    {
        cout << "\n Stop inhetiance destructed";
    }

private:
    StopInheritance()
    {
        cout << "\n Stop inhetiance ctr";
    }
    friend class Unique;
};

class Unique : virtual StopInheritance
{
public:
    Unique()
    {
        cout << " \n Unique object constructed";
    }

    ~Unique()
    {
        cout << " \n Unique object destructed";
    }
};

/* you can't do that now because derived will try to call grand parent i.e. StopInheritance ctr which is private */

// class derived : public Unique
// {
// public:
//     derived()
//     {
//         cout << " \n derived object constructed";
//     }

//     ~derived()
//     {
//         cout << " \n derived clasobjects destructed";
//     }
// };

int main()
{
    Unique u1;
    return 0;
}