/*
 * Created on Fri Dec 31 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#ifndef __ADAPTER_DESIGN__
#define __ADAPTER_DESIGN__

#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Client Class
class AndroidMarket
{
public:
    virtual ~AndroidMarket() = default;
    virtual string installFeature() = 0;
};

class AndroidPhone : public AndroidMarket
{
public:
    ~AndroidPhone()
    {
        cout << "AndroidPhone destroyed now"
             << "\n\n";
    }
    AndroidPhone()
    {
        cout << "AndroidPhone created now"
             << "\n\n";
    }
    virtual string installFeature() override
    {
        return "It's compatible with android and ready to install \n\n";
    }
};

// 3rd Party Library class
class ApplePhone
{
public:
    ~ApplePhone()
    {
        cout << "ApplePhone destroyed"
             << "\n\n";
    }
    ApplePhone()
    {
        cout << "ApplePhone created"
             << "\n\n";
    }
    string MacApp()
    {
        return "I am a MacApp \n\n";
    }
};

class ConvertMacToAndroid : public AndroidMarket
{
private:
    ApplePhone *applePhone;

public:
    ~ConvertMacToAndroid()
    {
        cout << "ComvertMacToAndroid destroyed"
             << "\n\n";
    }

    ConvertMacToAndroid(ApplePhone *_applephone) : applePhone(_applephone)
    {
        cout << "ComvertMacToAndroid created"
             << "\n\n";
    }
    string installFeature();
};

void CallAdapterDesign();
#endif