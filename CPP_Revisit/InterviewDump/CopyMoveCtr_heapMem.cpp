#include <iostream>

using namespace std;

class base
{
private:
    int *data;

public:
    base(int dt) : data(new int(dt))
    {
        cout << "Parameter Ctr called with data: " << *data << endl;
    }
    ~base()
    {
        cout << "Destructor called..!!" << endl;
        if (data != nullptr)
        {
            delete data;
            data = nullptr;
        }
    }
    int getData() const
    {
        return *data;
    }
    base(const base &other)
    {
        cout << "Copy ctr..!!!" << endl;

        data = new int;
        *data = *other.data;
    }
    base &operator=(const base &other)
    {
        cout << "Copy assignment opr..!!!" << endl;
        if (this != &other)
        {
            delete data;
            data = new int;
            *data = *other.data;
        }
        return *this;
    }
    base(base &&other) noexcept : data(other.data)
    {
        cout << "Move ctr...!!!" << endl;
        other.data = nullptr;
    }

    base &operator=(base &&other) noexcept
    {
        cout << "Move assignment opr..!!!" << endl;
        if (this != &other)
        {
            delete data;
            this->data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};

// template <typename T>
// void swapz(T *x, T *y)
// {
//     std::cout << "Copy function... !!!" << endl;
//     T temp(0);
//     temp = *y;
//     *y = *x;
//     *x = temp;
// }

template <typename T>
void swapz(T *x, T *y)
{
    std::cout << "Move function... !!!" << endl;
    T temp = std::move(*y);
    *y = std::move(*x);
    *x = std::move(temp);
}

int main()
{
    float a = 10, b = 20;
    base b1(10), b2(20);
    base *p1 = new base(30);
    base *p2 = new base(40);
    // swap(&a, &b);
    // swapz(&b1, &b2);
    // swapz(p1, p2);
    swapz(p1, p2);
    cout << p1->getData() << " " << p2->getData() << endl;
    delete p1;

    delete p2;
    // cout << "a: " << a << "b: " << b << endl;
    return 0;
}