#include <iostream>
#include <stdlib.h>
#include <mutex>
#include <atomic>

using namespace std;

class cSingleton
{
public:
    static cSingleton *getInstance()
    {
        if (instance.load() == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (instance.load() == nullptr)
            {
                instance.store(new cSingleton());
            }
        }
        return instance.load();
    }

    void DoSomething()
    {
        cout << "Singleton using new"
             << "\n\n";
    }

    static void destroyInstance()
    {
        lock_guard<mutex> lock(mtx);
        cSingleton *ptr = instance.load();
        if (ptr != nullptr)
        {
            cout << " Destroing instance ptr..\n\n";
            instance.store(nullptr);
            delete ptr;
        }
    }

private:
    static atomic<cSingleton *> instance;
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

atomic<cSingleton *> cSingleton::instance = nullptr;
mutex cSingleton::mtx;

int main()
{
    cSingleton *singleton1 = cSingleton::getInstance();
    // singleton1->DoSomething();

    cSingleton *singleton2 = cSingleton::getInstance();
    // singleton2->DoSomething();

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

    cSingleton::destroyInstance();

    return 0;
}
