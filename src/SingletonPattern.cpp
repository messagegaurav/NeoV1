/*
 * Created on Sun Dec 26 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include "SingletonPattern.h"

using namespace std;

// cSingleton *cSingleton::singlePtr = nullptr;

cSingleton::cSingleton()
{
    cout << "I am alive now"
         << "\n\n";
}

cSingleton::~cSingleton()
{
    cout << "dead now"
         << "\n\n";
}

cSingleton &cSingleton::getInstance()
{
    // if (singlePtr != nullptr)
    // {
    //     singlePtr = new cSingleton;
    //     return singlePtr;
    // }
    // else
    // {
    //     return singlePtr;
    // }

    // GA: using scott meyes method with stack object that inturn calls constructor and destructor for no memory leaks instead using new.
    static cSingleton singlePtr;
    return singlePtr;
}

void cSingleton::DoSomething()
{
    cout << "doing something"
         << "\n\n";
}

void CallSingleton()
{
    // unique_ptr<cSingleton> ptr(cSingleton::getInstance());


    cSingleton *ptr = &(cSingleton::getInstance());
    ptr->DoSomething();

    cSingleton *ptr1 = &(cSingleton::getInstance());
    ptr1->DoSomething();

    cout << "ptr = " << ptr << "\n\n";
    cout << "ptr1 = " << ptr1 << "\n\n";
}
