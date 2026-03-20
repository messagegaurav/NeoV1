#include <iostream>

using namespace std;

template <typename T>
class SmartPtr
{
private:
    T *ptr;
    int *refCount;
    void cleanUp()
    {
        if (refCount)
        {
            if (--(*refCount) == 0)
            {
                delete ptr;
                delete refCount;
            }
            ptr = nullptr;
            refCount = nullptr;
        }
    }

public:
    SmartPtr(T *p = nullptr) : ptr(p), refCount(new int(1))
    {
        if (!ptr)
        {
            delete refCount;
            refCount = nullptr;
        }
    }
    SmartPtr(const SmartPtr &other)
    {
        ptr = other.ptr;
        refCount = other.refCount;
        (*refCount)++;
    }

    SmartPtr &operator=(const SmartPtr &other)
    {
        if (this != &other)
        {
            cleanUp();
            ptr = other.ptr;
            refCount = other.refCount;
            if (ptr)
            {
                (*refCount)++;
            }
        }
        return *this;
    }

    ~SmartPtr()
    {
        cleanUp();
    }

    SmartPtr(SmartPtr &&other) noexcept
    {
        ptr = move(other.ptr);
        refCount = move(other.refCount);
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    SmartPtr &operator=(SmartPtr &&other) noexcept
    {
        if (this != &other)
        {
            cleanUp();
            ptr = move(other.ptr);
            refCount = move(other.refCount);
            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    int use_count() const
    {
        return refCount ? *refCount : 0;
    }

    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }
    T *get() const
    {
        return ptr;
    }
};

int main()
{
    SmartPtr<int> S1(new int(20));
    SmartPtr<int> S2 = S1;
    cout << "S1: " << *S1 << "  S1->refCount: " << S1.use_count() << "        S2: " << *S2 << " S2 refCount: " << S2.use_count() << endl;
    {
        SmartPtr<int> S3 = S1;
        cout << "S1: " << *S1 << "  S1->refCount: " << S1.use_count() << "        S2: " << *S2 << " S2 refCount: " << S2.use_count() << "        S3: " << *S3 << " S3 refCount: " << S3.use_count() << endl;
    }
    cout << "S1: " << *S1 << "  S1->refCount: " << S1.use_count() << "        S2: " << *S2 << " S2 refCount: " << S2.use_count() << endl;
    return 0;
}