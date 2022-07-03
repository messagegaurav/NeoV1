/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-04-03 13:11:55
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-04-03 14:44:35
 */

#include "mychrono.h"

template <typename T>
class SharedPtr
{
private:
    T *mPtr;
    inline static int ref_count;

public:
    SharedPtr()
    {
        cout << " \n default ctr....";
        mPtr = nullptr;
    }

    SharedPtr(T *_ptr) : mPtr(_ptr)
    {
        cout << "\n new smart pointer created and ownes raw object.... ";
        *mPtr = 20;
        ref_count = 1;
    }

    SharedPtr(const SharedPtr &_ptr)
    {

        if (_ptr.mPtr != nullptr)
        {
            cout << "\n\n copy ctr called.... wid ptr :  " << _ptr.mPtr << " value: " << *_ptr.mPtr;
            mPtr = _ptr.mPtr;
            ref_count++;
        }
        else
        {
            cout << "\n\n failed .... copy ctr object passed is invalid.. ";
        }
    }

    SharedPtr &operator=(SharedPtr &_ptr)
    {
        if (mPtr != nullptr)
        {
            delete mPtr;
        }
        if (_ptr.mPtr != mPtr)
        {
            mPtr = _ptr.mPtr;
            _ptr.mPtr = nullptr;
            ref_count++;
            return *this;
        }
        else
        {
            cout << "\n\n failed ....assignment oprt object passed is invalid.. ";
        }
    }

    SharedPtr(SharedPtr &&_ptr)
    {
        if ((_ptr.mPtr != nullptr) && (mPtr != _ptr.mPtr))
        {
            cout << "\n\n Move ctr called.... wid ptr :  " << _ptr.mPtr << " value: " << *_ptr.mPtr;
            mPtr = move(_ptr.mPtr);
            _ptr.mPtr = nullptr;
        }
        else
        {
            cout << "\n\n failed .... copy ctr object passed is invalid.. ";
        }
    }

    SharedPtr &operator=(SharedPtr &&_ptr)
    {

        if (mPtr != nullptr)
        {
            delete mPtr;
        }
        if (_ptr.mPtr != nullptr)
        {
            cout << "\n move assignment called....";
            mPtr = move(_ptr.mPtr);
            _ptr.mPtr = nullptr;
        }
        else
        {
            cout << "\n\n failed ....move assignment oprt object passed is invalid.. ";
        }
        return *this;
    }

    ~SharedPtr()
    {
        cout << "\n\n called destructor....";
        if (ref_count == 1)
        {
            cout << "\n\n last object .. deleting raw object..";
            delete mPtr;
            mPtr = nullptr;
            ref_count = 0;
        }
        else
        {
            ref_count--;
        }
    }

    T &operator*()
    {
        cout << "\n dereferncing it * ..";
        return *this->mPtr;
    }

    T *operator->()
    {
        cout << "\n dereferncing it with arrow..";
        return this->mPtr;
    }

    int getCount()
    {
        return this->ref_count;
    }

    T *get()
    {
        return this->mPtr;
    }
};

// GA: either you have to initialize static this way for template class or better declare it inline.

// template <typename T>
// int SharedPtr<T>::ref_count = 0;

int main()
{

    SharedPtr<int> myPtr(new int);
    cout << "\n myPtr count: " << myPtr.getCount();

    SharedPtr<int> ptr1 = myPtr;

    cout << "\n Ptr1 count: " << ptr1.getCount();

    ptr1 = move(myPtr);

    if (myPtr.get() == nullptr)
    {
        cout << "\n myPtr in correct state...";
    }

    cout << "\n Ptr1 count: " << ptr1.getCount();

    SharedPtr<int> ptr2 = move(ptr1);

    if (!ptr1.get())
    {
        cout << "\n ptr1 in correct state...";
    }

    cout << "\n Ptr1 count: " << ptr1.getCount();

    cout << "\n Ptr2 count: " << ptr2.getCount();

    cout
        << endl;
    return 0;
}