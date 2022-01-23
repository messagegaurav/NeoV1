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
public:
    base()
    {
        m_data = 5;
    }
    virtual void fun() {}

private:
    int m_data;
};

class enemy;
class player : public base
{
public:
    player() { m_data = 10; }

    void changeYdata(int _data) const
    {
        y_data = _data;
    }

    void playerData()
    {
        cout << "\n player: xdata: " << m_data << " y_data: " << y_data;
    }

private:
    int m_data;
    mutable int y_data;
};

class enemy : public base
{
public:
    enemy() { m_data = 20; }
    void enemyData()
    {
        cout << "\n enemy: data:  " << m_data;
    }

private:
    int m_data;
};

int main()
{
    base b1;
    enemy e1;
    base *b = new player();

    player *p = dynamic_cast<player *>(b);
    if (p)
    {
        p->changeYdata(35);
        p->playerData();
        cout << "\n dynamic cast succeeds";
    }
    else
    {

        cout << "\n dynamice cast Failed: NULL";
    }

    b = new enemy();
    player *p2 = static_cast<player *>(b);
    p2->playerData();

    // doesn't throw any exceptions thus dangerous thing but can be used to parse members individually from a container
    player *p3 = reinterpret_cast<player *>(b);
    p3->playerData();

    int *ptr = reinterpret_cast<int *>(&e1);
    cout << "\n reinterpret cast: " << *ptr;
    cout << "\n\n";
}