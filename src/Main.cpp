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
#include "SingletonPattern.h"
#include "AdapterDesign.h"

using namespace std;
using namespace chrono;

void call()
{
    // VectorGame();
    // StaticGame();
    // VectorWidSmartPointers();
    // delegationMethod();
    // executionTime();
    // CallSingleton();
    callBuilderClass();
    // PlayingWithFactories();
    // CallAdapterDesign();
}

int main()
{

    call();
    cout << "\n\n";
    return 0;
}
