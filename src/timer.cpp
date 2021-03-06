/*
 * Created on Tue Jun 08 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

// Understanding Nested Class concepts to help reduce coupling among components

#include "timer.h"

using namespace std;
using namespace chrono;

class Timer::Implementation
{
public:
    double elapsedTime()
    {
#ifdef WIN32
        return (GetTickCount() - mStartTime) / 1000;
#else
        struct timeval endTime;
        gettimeofday(&endTime, NULL);
        return endTime.tv_sec + (endTime.tv_usec / 1000000.0) - (mStartTime.tv_sec + (mStartTime.tv_usec) / 1000000.0);
#endif
    }

#ifdef WIN32
    DWORD mStartTime;
#else
    struct timeval mStartTime;
#endif

    double mDuration;
};

Timer::Timer(double data) : mpImpl(new Timer::Implementation())
{
    mpImpl->mDuration = data;
#ifdef WIN32
    mpImpl->mStartTime = GetTickCount();
#else
    gettimeofday(&(mpImpl->mStartTime), NULL);
#endif
}

Timer::~Timer()
{
    while (mpImpl->elapsedTime() < mpImpl->mDuration)
        ;
    delete mpImpl;
    mpImpl = NULL;
}

void callingTimer()
{
    double wait = 5;
    auto pTimer = make_unique<Timer>(wait);
}

void executionTime()
{
    auto start = high_resolution_clock::now();
    callingTimer();
    auto stop = high_resolution_clock::now();
    auto diff_time = duration_cast<seconds>(stop - start);
    cout << "\n\n Time taken: " << diff_time.count() << " ms";
}