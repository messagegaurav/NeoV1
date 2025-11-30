#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
public:
    shared_ptr<B> bPtr;
    A() {}
    ~A() { cout << "A destroyed ..!!!" << "\n\n"; }
};

class B
{
public:
    weak_ptr<A> aPtr;
    B() {}
    ~B() { cout << " B destroyed ... !!!" << "\n\n"; }
};

int main()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->bPtr = b;
    b->aPtr = a;
    cout << " a shared ptr count: " << a->bPtr.use_count() << "\n\n";
    cout << " b shared ptr count: " << b->aPtr.use_count() << "\n\n";
    return 0;
}