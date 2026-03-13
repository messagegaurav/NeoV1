#include <iostream>

using namespace std;

template <class T>
class SharedPtr
{
private:
    T *ptr;
    int *refCount;

public:
    explicit SharedPtr(T *p = nullptr) : ptr(p), refCount(new int(1)) {}

    SharedPtr(const SharedPtr &other) : ptr(other.ptr), refCount(other.refCount)
    {
        (*refCount)++;
    }

    SharedPtr &operator=(const SharedPtr &other)
    {
        if (this != &other)
        {
            if (--(*refCount) == 0)
            {
                delete ptr;
                delete refCount;
            }
            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
        }
        return *this;
    }

    SharedPtr(SharedPtr &&other) noexcept : ptr(other.ptr), refCount(other.refCount)
    {
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    SharedPtr &operator=(SharedPtr &&other) noexcept
    {
        if (this != &other)
        {
            if (--(*refCount) == 0)
            {
                delete ptr;
                delete refCount;
            }
            ptr = other.ptr;
            refCount = other.refCount;
            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }

    T *get() const { return ptr; }

    explicit operator bool() { return ptr != nullptr; }

    int use_count() const { return (refCount ? *refCount : 0); }
    void reset(T *p = nullptr)
    {
        if (--(*refCount) == 0)
        {
            delete ptr;
            delete refCount;
        }
        ptr = p;
        refCount = new int(1);
    }
};

int main()
{
    SharedPtr<int> p1(new int(20));
    SharedPtr<int> p2 = p1;
    SharedPtr<int> p3;
    p3 = p2;
    SharedPtr<int> p4 = move(p3);

    cout << " " << p4.use_count() << endl;

    return 0;
}