#include <iostream>

using namespace std;

template <class T>
class SmartPtr
{
private:
    T *ptr;

public:
    explicit SmartPtr(T *p = nullptr) : ptr(p) {}
    ~SmartPtr()
    {
        delete ptr;
    }
    SmartPtr(const SmartPtr &) = delete;
    SmartPtr &operator=(const SmartPtr &) = delete;
    SmartPtr(SmartPtr &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }
    SmartPtr &operator=(SmartPtr &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }
    T *get() const { return ptr; }

    explicit operator bool() const { return ptr != nullptr; }

    T *release()
    {
        T *temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T *p = nullptr)
    {
        delete ptr;
        ptr = p;
    }
};

int main()
{
    SmartPtr<int> b1(new int(10));
    SmartPtr<int> p1 = move(b1);

    int *raw = p1.release();
    delete raw;
    b1.reset(new int(30));
    return 0;
}