#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class observer;
class COV
{
private:
    int data;
    vector<observer *> myObs;

public:
    void registerClient(observer *obs);

    void unregisterClient(observer *obs);
    void notify(int val);

    void setVal(int val)
    {
        data = val;
        cout << "COV: data: " << data << endl;
        if (data)
            notify(val);
    }
};

class observer
{
private:
    int id;

public:
    observer(int Id) : id(Id)
    {
    }
    void notified(int data) const
    {
        cout << "Notified: " << id << " " << "COV: " << data << endl;
    }
    int getId()
    {
        return id;
    }
};

void COV::notify(int data)
{
    for (const auto &ch : myObs)
    {
        ch->notified(data);
    }
}

void COV::registerClient(observer *obs)
{
    if (obs != nullptr)
    {
        myObs.emplace_back(obs);
        cout << "Registered.. id: " << obs->getId() << endl;
    }
}

void COV::unregisterClient(observer *obs)
{
    if (obs != nullptr)
    {
        auto itr = find(myObs.begin(), myObs.end(), obs);
        if (itr != myObs.end())
        {
            cout << "Unregistered id: " << (*itr)->getId() << endl;
            myObs.erase(itr);
        }
    }
}

int main()
{
    COV cov1;
    observer ob1(1);
    observer ob2(2);
    observer ob3(3);

    cov1.registerClient(&ob1);
    cov1.registerClient(&ob2);
    cov1.registerClient(&ob3);

    cov1.setVal(40);

    cov1.unregisterClient(&ob2);
    cov1.setVal(30);
    return 0;
}