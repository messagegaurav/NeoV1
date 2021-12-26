/*
 * Created on Sun Dec 26 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;
class cSingleton
{

public:
    static cSingleton &getInstance();

    ~cSingleton();
    void DoSomething();

private:
    // static cSingleton *singlePtr;
    cSingleton();
    cSingleton(const cSingleton &) = delete;
    cSingleton(cSingleton &&) = delete;
    cSingleton &operator=(const cSingleton &) = delete;
};

void CallSingleton();
