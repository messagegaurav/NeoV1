/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-31 22:26:59
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-31 23:52:20
 */

// #include <memory>
#include "mychrono.h"

template <typename T>
class UniquePtr
{
private:
    T *smartPtr;

public:
    UniquePtr(T *_ptr) : smartPtr(_ptr)
    {
        *smartPtr = 20;
        cout << "\n new raw object created....";
    }

    UniquePtr(const UniquePtr<T> &_ptr) = delete;
    UniquePtr<T> &operator=(const UniquePtr<T> &_ptr) = delete;

    UniquePtr(UniquePtr<T> &&_ptr)
    {
        cout << "\n move ctr called....";
        if (smartPtr != nullptr)
        {
            cout << "\n deleted previous raw object.... ";
            delete smartPtr;
        }
        smartPtr = move(_ptr.smartPtr);
        _ptr.smartPtr = nullptr;
    }

    UniquePtr<T> &operator=(UniquePtr<T> &&_ptr)
    {
        cout << "\n move assignment operator called....";
        if (smartPtr != nullptr)
        {
            delete smartPtr;
        }
        if (smartPtr != _ptr.smartPtr)
        {
            smartPtr = move(_ptr.smartPtr);
            _ptr.smartPtr = nullptr;
        }
        return *this;
    }

    ~UniquePtr()
    {
        cout << "\n calling destructor...";
        if (smartPtr != nullptr)
        {
            delete smartPtr;
            smartPtr = nullptr;
        }
    }

    UniquePtr<T> &operator*()
    {
        return *this->smartPtr;
    }

    UniquePtr<T> *operator->()
    {
        return this->smartPtr;
    }
};

int main()
{
    UniquePtr<int> mySmart(new int);

    UniquePtr<int> ptr1 = move(mySmart);

    mySmart = move(ptr1);

    // error scenario coz mySmart.smartptr is already null
    // UniquePtr<int> ptr2 = move(mySmart);

    // error cannot use normal copy or move
    //  mySmart = ptr1;
    //  UniquePtr<int> ptr1 = mySmart;

    cout << endl;
    return 0;
}