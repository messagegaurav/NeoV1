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
#include "BuilderClass.h"
#include "AbstractFactoryMethod.h"

using namespace std;
using namespace chrono;

void call()
{
    // VectorGame();
    // StaticGame();
    // VectorWidSmartPointers();
    // delegationMethod();
    executionTime();
}

int main()
{
    // callBuilderClass();
    PlayingWithFactories();
    cout << "\n\n";
    return 0;
}
