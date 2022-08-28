/*
 * Created on Tue Jun 08 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

// Hiding, now all data members for Implementation are hidden from this header file
#ifndef __TIMER_CPP__
#define __TIMER_CPP__

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <chrono>
#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif
class Timer
{
public:
    explicit Timer(double);
    ~Timer();
    Timer(const Timer &);
    Timer &operator=(const Timer &);

private:
    class Implementation;
    Implementation *mpImpl;
};

void callingTimer();
void executionTime();

#endif