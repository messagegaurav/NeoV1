#include <iostream>
#include <stdlib.h>
#include <mutex>

using namespace std;

class cSingleton
{
public:
    static cSingleton *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new cSingleton();
            }
        }
        return instance;
    }

    void DoSomething()
    {
        cout << "Singleton using new"
             << "\n\n";
    }

    static void destroyInstance()
    {
        lock_guard<mutex> lock(mtx);
        if (instance != nullptr)
        {
            cout << " Destroing instance ptr..\n\n";
            delete instance;
            instance = nullptr;
        }
    }

private:
    static cSingleton *instance;
    static mutex mtx;
    cSingleton();
    ~cSingleton();
    cSingleton(const cSingleton &) = delete;
    cSingleton &operator=(const cSingleton &) = delete;
};

cSingleton::cSingleton()
{
    cout << " Singleton instance created with new..\n\n";
}

cSingleton::~cSingleton()
{
    cout << " Singleton instance destroyed..\n\n";
}

cSingleton *cSingleton::instance = nullptr;
mutex cSingleton::mtx;

int main()
{
    cSingleton *singleton1 = cSingleton::getInstance();
    // singleton1->DoSomething();

    cSingleton *singleton2 = cSingleton::getInstance();
    // singleton2->DoSomething();

    cSingleton::destroyInstance();

    if (singleton1 == singleton2)
    {
        cout << "Both instances are same"
             << "\n\n";
    }
    else
    {
        cout << "Both instances are different"
             << "\n\n";
    }

    return 0;
}
