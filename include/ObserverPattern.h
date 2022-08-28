/*
 * Created on Tue Jan 11 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#ifndef __OBSERVER_PATTERN__
#define __OBSERVER_PATTERN__

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Shop;
class Factory
{
public:
    virtual ~Factory(){};
    virtual void subscribe(Shop *pSuscribe) = 0;
    virtual void unsubscribe(Shop *pSubscrive) = 0;
    virtual void notify() = 0;
    virtual void setVal(int _data)
    {
        data = _data;
        notify();
    }
    virtual void clearAll() = 0;

protected:
    int data;
    vector<Shop *> notifyList;
};

class Shop
{
public:
    virtual ~Shop(){};
    virtual void update(int shopStatus) = 0;

    // protected:
    //     Factory *mpPublisher;
};

class ConcreteFactory : public Factory
{

public:
    void subscribe(Shop *pSubscribe) override
    {
        cout << "Pushing subcriber: \n\n";
        notifyList.push_back(pSubscribe);
    }

    void unsubscribe(Shop *pSubscribe) override
    {
        cout << " Unsubscribed !!\n\n";
        notifyList.erase(std::remove(notifyList.begin(), notifyList.end(), pSubscribe), notifyList.end());
    }

    void notify() override
    {
        cout << " Notifying ... \n\n";
        for (auto itr : notifyList)
        {
            itr->update(data);
        }
    }

    void clearAll() override
    {
        cout << "Clearing subscribers \n\n";
        notifyList.clear();
    }
    ~ConcreteFactory()
    {
        cout << "Concerete factory dead \n";
    }
};

class Shops : public Shop
{
public:
    // Shops(Factory *pPublisher) : mpPublisher(pPublisher)
    // {
    //     cout << "Observer created ";
    // }
    Shops()
    {
        cout << "Observer created \n\n";
    }
    void update(int shopStatus)
    {
        cout << " I got notified with shop status = " << shopStatus << "\n\n";
    }
    ~Shops()
    {
        cout << "Observer dead \n\n";
    }
};

void callObserverPattern();

#endif // !__OBSERVER_PATTERN__
