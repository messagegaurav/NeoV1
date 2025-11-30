#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class Sptr
{
private:
    T *mPtr;       // managed raw pointer
    int *refcount; // shared reference count (heap-allocated)

    void release()
    {
        // If we have a refcount, decrement and free resources when it hits zero
        if (refcount)
        {
            if (--(*refcount) == 0)
            {
                cout << "ref count: " << *refcount << "\n\n";
                delete mPtr;     // delete managed object
                delete refcount; // delete refcount storage
            }
            // Null out to avoid dangling after release/move
            mPtr = nullptr;
            refcount = nullptr;
        }
    }

public:
    Sptr(T *ptr = nullptr) : mPtr(ptr), refcount(new int(1))
    {
        // If constructed empty, set count to 0 (no owners)
        if (!mPtr)
        {
            *refcount = 0;
        }
    }

    // Copy constructor: share ownership and increment count
    Sptr(const Sptr &other) : mPtr(other.mPtr), refcount(other.refcount)
    {
        if (mPtr)
        {
            (*refcount)++;
        }
    }

    // Move constructor: transfer ownership, null out source
    Sptr(Sptr &&other) : mPtr(other.mPtr), refcount(other.refcount)
    {
        other.mPtr = nullptr;
        other.refcount = nullptr;
    }

    // Move assignment: release current, steal other's resources
    Sptr &operator=(Sptr &&other)
    {
        if (this != &other)
        {
            release();
            mPtr = other.mPtr;
            refcount = other.refcount;
            other.mPtr = nullptr;
            other.refcount = nullptr;
        }
        return *this;
    }

    // Copy assignment: release current, share ownership, increment count
    Sptr &operator=(const Sptr &other)
    {
        if (this != &other)
        {
            release();
            mPtr = other.mPtr;
            refcount = other.refcount;
            if (mPtr)
                ++(*refcount);
        }
        return *this;
    }

    ~Sptr()
    {
        // Decrement count and free when last owner
        release();
    }

    T *operator->() const
    {
        return mPtr;
    }

    T &operator*() const
    {
        return *mPtr;
    }

    // Access raw pointer (non-owning)
    T *get() const
    {
        return mPtr;
    }

    // Current shared owner count
    int use_count() const
    {
        // Guard for moved-from (nullptr) refcount
        return refcount ? *refcount : 0;
    }
};

int main()
{
    Sptr<int> sp1(new int(20));
    cout << "sp1-> val: " << *sp1 << " refcount: " << sp1.use_count() << "\n\n";

    Sptr<int> sp2 = sp1; // share ownership
    cout << "sp2-> val: " << *sp2 << " refcount: " << sp2.use_count() << "\n\n";

    {
        Sptr<int> sp3 = sp2; // share ownership in inner scope
        cout << "sp3-> val: " << *sp3 << " refcount: " << sp3.use_count() << "\n\n";
        // sp3 goes out of scope here, refcount decrements
    }

    cout << "After sp3 destroyed, refcount now: " << sp1.use_count() << "\n\n";

    return 0;
}