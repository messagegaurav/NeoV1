#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Bacnet Point Observer
class cBacnetObserver
{
public:
    virtual void bacnetPointUpdate(const string &pointId, int value) = 0;
    virtual ~cBacnetObserver()
    {
        cout << "\n base interface cBacnetObserver destroyed...!!!!\n\n";
    }
};

// Bacnet Subject being Observed
class cBacnetSubject
{
public:
    virtual void registerObs(cBacnetObserver *bacnetObs) = 0;
    virtual void unregisterObs(cBacnetObserver *bacnetObs) = 0;
    virtual void notifyObs(const string &pointId, int value) = 0;
    virtual ~cBacnetSubject()
    {
        cout << "\n base interface cBacnetSubject destroyed...!!!!\n\n";
    }
};

class cBacnetPointSubject : public cBacnetSubject
{
private:
    vector<cBacnetObserver *> observers;
    int pointValue;
    string pointId;

public:
    cBacnetPointSubject(const string &id) : pointId(id), pointValue(0) {}
    void registerObs(cBacnetObserver *bacnetObs) override
    {
        cout << "Registering Bacnet Observer for Point ID: " << pointId << endl;
        observers.push_back(bacnetObs);
    }

    void unregisterObs(cBacnetObserver *bacnetObs) override
    {
        cout << "Unregistering Bacnet Observer for Point ID: " << pointId << endl;
        observers.erase(remove(observers.begin(), observers.end(), bacnetObs), observers.end());
    }

    void notifyObs(const string &pointId, int value) override
    {
        cout << "Notifying Observers of Point ID: " << pointId << " with new value: " << value << endl;
        for (auto obs : observers)
        {
            obs->bacnetPointUpdate(pointId, value);
        }
    }

    void setPointValue(int value)
    {
        cout << "Setting Point ID: " << pointId << " to value: " << value << endl;
        if (pointValue != value)
        {
            pointValue = value;
            notifyObs(pointId, pointValue);
        }
    }

    virtual ~cBacnetPointSubject()
    {
        cout << "cBacnetPointSubject destroyed...!!!!\n\n";
    }
};

class cBacnetUIObs : public cBacnetObserver
{
public:
    void bacnetPointUpdate(const string &pointId, int value) override
    {
        cout << "Bacnet UI Observer received update - Point ID: " << pointId << " New Value: " << value << endl;
    }

    ~cBacnetUIObs()
    {
        cout << "cBacnetUIObs Observer destroyed...!!!!\n\n";
    }
};

class cBacnetLogger : public cBacnetObserver
{
public:
    void bacnetPointUpdate(const string &pointId, int value) override
    {
        cout << "Bacnet Logger Observer received update - Point ID: " << pointId << " New Value: " << value << endl;
    }

    ~cBacnetLogger()
    {
        cout << "cBacnetLogger Observer destroyed...!!!!\n\n";
    }
};

int main()
{
    cBacnetPointSubject bacnetPoint1("AnalogPoint");
    cBacnetUIObs observer1;
    cBacnetLogger observer2;
    bacnetPoint1.registerObs(&observer1);

    bacnetPoint1.setPointValue(10);

    bacnetPoint1.registerObs(&observer2);
    bacnetPoint1.setPointValue(20);

    bacnetPoint1.unregisterObs(&observer1);
    bacnetPoint1.setPointValue(30);

    return 0;
}