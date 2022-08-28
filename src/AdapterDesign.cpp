/*
 * Created on Fri Dec 31 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include "AdapterDesign.h"

using namespace std;

string ConvertMacToAndroid::installFeature()
{
    // Do some conversion magic form Mac to Android
    string temp = this->applePhone->MacApp();
    temp = temp + "but now I am available in android market";
    return temp;
}

void CallAdapterDesign()
{
    AndroidPhone androidPhone;
    cout << androidPhone.installFeature() << "\n\n";

    ApplePhone applePhone;
    cout << applePhone.MacApp() << "\n\n";

    ConvertMacToAndroid convertMac(&applePhone);
    cout << convertMac.installFeature() << "\n\n";
}