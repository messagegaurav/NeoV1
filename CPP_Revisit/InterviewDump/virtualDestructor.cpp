#include <iostream>

using namespace std;

class base
{
public:
    base() { show(); }
    virtual void show()
    {
        cout << "base show" << endl;
    }
};

class derived : public base
{
public:
    void show() override
    {
        cout << "derived show" << endl;
    }
};

int main()
{
    base *b1 = new derived();
    delete b1;
    return 0;
}