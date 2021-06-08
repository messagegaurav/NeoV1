/*
 * Created on Tue Jun 08 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include "ObjectRelations.h"

using namespace std;

void delegationMethod()
{
    auto w1 = make_unique<Windows>(new Circle(10.2));
    cout << "\n Object area :" << w1->area();
    auto w2 = make_unique<Windows>(new Rectangle(10, 12));
    cout << "\n Object area: " << w2->area();
}
