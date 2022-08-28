/*
 * Created on Sun Jan 09 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

// Decorator/Wrapper pattern helps you to attache additional behaviour/services to object
// at run time
#ifndef __DECORATOR_PATTERN__
#define __DECORATOR_PATTERN__

#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

class Car
{
public:
    Car()
    {
        cout << "Car created\n";
    }
    ~Car()
    {
        cout << "Car destroyed\n";
    }

    virtual inline string getInfo() { return _info; }
    virtual float costPrice() = 0;

private:
    string _info;
};

class BaseCar : public Car
{
public:
    BaseCar()
    {
        cout << "Base Car model created\n";
    }
    ~BaseCar()
    {
        cout << "Base Car model destroyed\n";
    }
    float costPrice()
    {
        return 2000;
    }
    string getInfo()
    {
        return "Base Model";
    }
};

// Decorator interface
class DecoratorCar : public Car
{
public:
    virtual string getInfo() = 0;
    virtual ~DecoratorCar()
    {
        cout << "DecorateCar destroyed \n";
    }
};

// Decorating concrete sub classes
class Navigation : public DecoratorCar
{
private:
    Car *mpMyCar;

public:
    Navigation(Car *_car)
    {
        mpMyCar = _car;
    }
    string getInfo()
    {
        return mpMyCar->getInfo() + "+ Navigation";
    }
    float costPrice()
    {
        return 200 + mpMyCar->costPrice();
    }
    ~Navigation()
    {
        cout << " Navigation object destroyed \n";
    }
};

class AlloyWheels : public DecoratorCar
{
private:
    Car *mpMyCar;

public:
    string getInfo()
    {
        return mpMyCar->getInfo() + "+ AlloyWheels";
    }
    float costPrice()
    {
        return 100 + mpMyCar->costPrice();
    }

    ~AlloyWheels()
    {
        cout << " AlloyWheels object destroyed \n";
    }
    AlloyWheels(Car *_car)
    {
        mpMyCar = _car;
    }
};

void CallDecoratorPattern()
{
    Car *myCar = new BaseCar;
    cout << "Car Model: " << myCar->getInfo() << " at Price: " << myCar->costPrice() << "\n\n";

    // adding features to it yayyy
    myCar = new Navigation(myCar);
    cout << "Car Model: " << myCar->getInfo() << " at Price: " << myCar->costPrice() << "\n\n";

    myCar = new AlloyWheels(myCar);
    cout << "Car Model: " << myCar->getInfo() << " at Price: " << myCar->costPrice() << "\n\n";

    delete[] myCar;
}

#endif // !__DECORATOR_PATTERN__
