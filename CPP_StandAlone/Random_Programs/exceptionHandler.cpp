/*
 * Created on Fri Jan 21 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>

using namespace std;

class base
{
public:
    base()
    {
        cout << "\n base: :) I am constructed";
    }
    ~base()
    {
        cout << "\n base: :( I am destructed";
    }
};

class derived : public base
{
public:
    base b;
    derived() = default;

    derived(int) : derived{}
    {
        base b;
        throw std::exception{};
        cout << "\n :| derived am I constructed...";
    }
    ~derived()
    {
        cout << "\n :( derived: I am destructed";
    }
};

int main()
{
    try
    {
        derived d;
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Default catch exception";
    }
    return 0;
}