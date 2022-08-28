/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-15 14:57:44
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-15 16:34:47
 */

#include <iostream>
#include <string.h>
#include <memory>

using namespace std;

class base
{
private:
    int data;

public:
    base(int _data) : data(_data)
    {
    }
    void printVal()
    {
        cout << "\n data: " << data;
    }
};

template <typename T>
class UniquePtr
{
private:
    T *smartPtr;

public:
    UniquePtr() : smartPtr(nullptr)
    {
    }
    UniquePtr(T *_ptr) : smartPtr(_ptr)
    {
        cout << "\n raw object created...and pointed by Unique_ptr...";
    }

    UniquePtr(const UniquePtr &ptr) = delete;
    UniquePtr &operator=(const UniquePtr &ptr) = delete;

    UniquePtr &operator=(UniquePtr &&_ptr)
    {
        if (this == &_ptr)
        {
            return *_ptr;
        }
        if (this != nullptr)
        {
            delete this->smartPtr;
        }
        else
        {
            smartPtr = move(_ptr);
            _ptr = nullptr;
        }
        return *this;
    }

    UniquePtr(UniquePtr &&_ptr)
    {
        // smartPtr = move(_ptr);
        *smartPtr = *_ptr;
        _ptr = nullptr;
    }

    UniquePtr *operator->()
    {
        return smartPtr;
    }
    UniquePtr &operator*()
    {
        return *smartPtr;
    }

    ~UniquePtr()
    {
        if (smartPtr != nullptr)
        {
            delete smartPtr;
            smartPtr = nullptr;
        }
    }
};

int main()
{
    UniquePtr<base> ptr(new base(20));

    UniquePtr<base> ptr1 = move(ptr);
}