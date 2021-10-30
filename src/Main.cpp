/*
 * Created on Tue Jun 08 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <MoveCtr.h>
#include <stdlib.h>
#include "ObjectRelations.h"
#include "timer.h"
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    // VectorGame();
    // StaticGame();
    // VectorWidSmartPointers();
    // delegationMethod();
    auto start = high_resolution_clock::now();
    callingTimer();
    auto stop = high_resolution_clock::now();
    auto diff_time = duration_cast<seconds>(stop - start);
    cout << "\n\n Time take: " << diff_time.count();

    cout << "\n\n";
    return 0;
}