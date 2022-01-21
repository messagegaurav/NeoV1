/*
 * Created on Thu Jan 20 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <memory>

using namespace std;
class base
{
    virtual void fun() {}
};

class player : public base
{
public:
    void hoho()
    {
        cout << "\n hoho";
    }
};

class enemy : public base
{
public:
    void hehe()
    {
        cout << "\n damn ";
    }
};

int main()
{
    player *p;
    base *b = new enemy();
    base b1;
    player p1;
    p = dynamic_cast<player *>(&p1);
    if (p)
    {
        cout << "\n pass";
    }
    else
    {
        cout << "\n fail";
    }

    player *p2 = static_cast<player *>(b);
    p2->hoho();
    cout << "\n\n";
}