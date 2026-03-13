/*
 * Created on Thu Jan 20 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <string.h>

using namespace std;

template <class T>
class SmartPtr
{
private:
    T *ptr;

public:
    // Constructor
    explicit SmartPtr(T *p = nullptr) : ptr(p)
    {
        cout << "\n constructed..";
    }

    // Destructor
    ~SmartPtr()
    {
        delete ptr;
        cout << "\n destructed";
    }

    // Delete copy constructor and copy assignment (unique ownership)
    SmartPtr(const SmartPtr &) = delete;
    SmartPtr &operator=(const SmartPtr &) = delete;

    // Move constructor (transfer ownership)
    SmartPtr(SmartPtr &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
        cout << "\n move constructed";
    }

    // Move assignment (transfer ownership)
    SmartPtr &operator=(SmartPtr &&other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
            cout << "\n move assigned";
        }
        return *this;
    }

    // Dereference operators
    T &operator*() const { return *ptr; }
    T *operator->() const { return ptr; }

    // Get raw pointer
    T *get() const { return ptr; }

    // Check if pointer is valid
    explicit operator bool() const { return ptr != nullptr; }

    // Release ownership (returns raw pointer, doesn't delete)
    T *release()
    {
        T *temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Reset pointer (deletes old, takes new)
    void reset(T *p = nullptr)
    {
        delete ptr;
        ptr = p;
    }
};

int main()
{
    // Basic usage
    SmartPtr<int> ptr1(new int(20));
    cout << "\n val: " << *ptr1;

    // Move semantics
    SmartPtr<int> ptr2 = std::move(ptr1); // Ownership transferred
    cout << "\n ptr2 val: " << *ptr2;

    // Check validity
    if (ptr2)
        cout << "\n ptr2 is valid";

    // Reset
    ptr2.reset(new int(30));
    cout << "\n ptr2 after reset: " << *ptr2;

    // Release ownership
    int *raw = ptr2.release();
    cout << "\n raw val: " << *raw;
    delete raw; // Manual cleanup needed

    return 0;
}
