#include <iostream>
using namespace std;

template <class T>
class SharedPtr
{
private:
    T *ptr;
    int *refCount;

public:
    // Constructor
    explicit SharedPtr(T *p = nullptr) : ptr(p), refCount(new int(1))
    {
        cout << "\n constructed, refCount: " << *refCount;
    }

    // Destructor
    ~SharedPtr()
    {
        cout << "\n destructor called, refCount before: " << *refCount;
        if (--(*refCount) == 0)
        {
            delete ptr;
            delete refCount;
            cout << " -> deleted resource";
        }
    }

    // Copy constructor (share ownership)
    SharedPtr(const SharedPtr &other) : ptr(other.ptr), refCount(other.refCount)
    {
        (*refCount)++;
        cout << "\n copy constructor, refCount: " << *refCount;
    }

    // Copy assignment
    SharedPtr &operator=(const SharedPtr &other)
    {
        if (this != &other)
        {
            cout << "\n copy assignment";
            // Decrease current refCount
            if (--(*refCount) == 0)
            {
                delete ptr;
                delete refCount;
                cout << " -> old resource deleted";
            }
            // Share new resource
            ptr = other.ptr;
            refCount = other.refCount;
            (*refCount)++;
            cout << ", new refCount: " << *refCount;
        }
        return *this;
    }

    // Move constructor
    SharedPtr(SharedPtr &&other) noexcept : ptr(other.ptr), refCount(other.refCount)
    {
        other.ptr = nullptr;
        other.refCount = nullptr;
        cout << "\n move constructor";
    }

    // Move assignment
    SharedPtr &operator=(SharedPtr &&other) noexcept
    {
        if (this != &other)
        {
            cout << "\n move assignment";
            if (refCount && --(*refCount) == 0)
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
    int use_count() const { return refCount ? *refCount : 0; }
    explicit operator bool() const { return ptr != nullptr; }

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
    cout << "=== Step 1: Create p1 ===";
    SharedPtr<int> p1(new int(10));
    cout << "\n p1 refCount: " << p1.use_count();
    cout << "\n p1 value: " << *p1;

    cout << "\n\n=== Step 2: Copy p1 to p2 ===";
    SharedPtr<int> p2 = p1; // Copy constructor
    cout << "\n p1 refCount: " << p1.use_count();
    cout << "\n p2 refCount: " << p2.use_count();
    cout << "\n Both point to same value: " << *p1 << " = " << *p2;

    cout << "\n\n=== Step 3: Create p3 with different value ===";
    SharedPtr<int> p3(new int(20));
    cout << "\n p3 refCount: " << p3.use_count();
    cout << "\n p3 value: " << *p3;

    cout << "\n\n=== Step 4: Assign p1 to p3 ===";
    p3 = p1; // Copy assignment (p3's old resource deleted)
    cout << "\n p1 refCount: " << p1.use_count();
    cout << "\n p2 refCount: " << p2.use_count();
    cout << "\n p3 refCount: " << p3.use_count();
    cout << "\n All point to same value: " << *p1 << " = " << *p2 << " = " << *p3;

    cout << "\n\n=== Step 5: Move p1 to p4 ===";
    SharedPtr<int> p4 = move(p1); // Move constructor
    cout << "\n p1 refCount: " << p1.use_count() << " (moved from)";
    cout << "\n p4 refCount: " << p4.use_count();

    cout << "\n\n=== Step 6: Exiting main (destructors called) ===";
    return 0;
}
