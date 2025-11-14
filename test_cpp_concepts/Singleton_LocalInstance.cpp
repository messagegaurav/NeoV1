#include <iostream>
#include <stdlib.h>

using namespace std;

// C++ 11 thread safe version using static local instance
class cSingleton
{
public:
    static cSingleton &getInstance()
    {
        static cSingleton instance;
        return instance;
    }

    void DoSomething()
    {
        cout << "doing something in Singleton" << "\n\n";
    }

private:
    // static cSingleton *singlePtr;
    cSingleton();
    ~cSingleton();

    cSingleton(const cSingleton &) = delete;            // Copy Constructor
    cSingleton &operator=(const cSingleton &) = delete; // Copy Assignment Operator
};

cSingleton::cSingleton()
{
    cout << "cSingleton I am alive now"
         << "\n\n";
}

cSingleton::~cSingleton()
{
    cout << "cSingleton dead now"
         << "\n\n";
}

int main()
{
    cSingleton &singleton1 = cSingleton::getInstance();
    singleton1.DoSomething();

    cSingleton &singleton2 = cSingleton::getInstance();
    singleton2.DoSomething();

    if (&singleton1 == &singleton2)
    {
        cout << "Both instances are same"
             << "\n\n";
    }
    else
    {
        cout << "Both instances are different"
             << "\n\n";
    }

    cin.get();

    return 0;
}
