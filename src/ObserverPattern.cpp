/*
 * Created on Tue Jan 11 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include "ObserverPattern.h"

using namespace std;

void callObserverPattern()
{
    Factory *pConcreteFactory = new ConcreteFactory();
    Shops *shop1 = new Shops();
    Shops *shop2 = new Shops();
    Shops *shop3 = new Shops();

    pConcreteFactory->subscribe(shop1);
    pConcreteFactory->subscribe(shop2);
    pConcreteFactory->subscribe(shop3);

    pConcreteFactory->setVal(20);

    pConcreteFactory->unsubscribe(shop3);

    pConcreteFactory->setVal(10);

    pConcreteFactory->clearAll();

    delete pConcreteFactory;
    delete shop1;
    delete shop2;
    delete shop3;
}