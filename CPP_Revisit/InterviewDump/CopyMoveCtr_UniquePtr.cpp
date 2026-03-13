#include <iostream>
#include <memory>

using namespace std;
class base
{
private:
    std::unique_ptr<int> data;

public:
    base(int dt) : data(make_unique<int>(dt))
    {
        cout << "Param Ctr with data: " << *data << endl;
    }

    ~base()
    {
        cout << "Def Destructor...!!!" << endl;
    }

    base(const base &other) = delete;

    base &operator=(const base &other) = delete;

    base(base &&other) noexcept : data(move(other.data))
    {
        cout << "Move Ctr..!!!" << endl;
    }

    base &operator=(base &&other) noexcept
    {
        cout << "Move assignment opr..!!!" << endl;
        if (this != &other)
        {
            data = move(other.data);
        }
        return *this;
    }

    int getData() const
    {
        if (data != nullptr)
            return *data;
        else
            return 0;
    }
};

template <typename T>
void swap(T *x, T *y)
{
    cout << "Swapping.. !!!" << endl;
    T temp = move(*x);
    *x = move(*y);
    *y = move(temp);
}

int main()
{
    base *b1 = new base(10);
    base *b2 = new base(20);
    swap(b1, b2);
    cout << "b1: " << b1->getData() << "b2: " << b2->getData() << endl;
    delete b1;
    delete b2;
    return 0;
}