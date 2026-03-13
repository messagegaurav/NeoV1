#include <iostream>

using namespace std;
class base
{
private:
public:
    virtual void show() { cout << "base show() !!!!" << endl; }
    virtual ~base() { cout << "base destroyed...!!!" << endl; }
};

class derived : public base
{
private:
public:
    void show() { cout << "derived show() !!!!" << endl; }
    void getShow() { cout << "getSHow()...!!!" << endl; }
    ~derived() { cout << "derived destroyed...!!!" << endl; }
};

int main()
{
    // base b1;
    // derived d1;
    base *b1 = new derived();
    derived *d1 = dynamic_cast<derived *>(b1);
    b1->show();
    d1->show();
    d1->getShow();
    dynamic_cast<derived *>(b1)->getShow();
    delete b1;
    // cout << sizeof(b1) << " " << sizeof(d1) << endl;
    return 0;
}