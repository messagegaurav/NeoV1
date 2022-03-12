/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-06 22:46:14
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-07 01:35:16
 */

#include <stack>
#include <iostream>
#include <string.h>
#include <ctime>
#include <chrono>
#include <memory>
#include <vector>

using namespace std;
using namespace std::chrono;

class base
{
    string data;

public:
    base()
    {
        cout << "\n default ctr called..";
    }
    base(string _str) : data(_str)
    {
        cout << "\n base constructed with: " << data;
    }

    void printVal()
    {
        cout << "\n data: " << data;
    }

    // copy ctr begins
    base(const unique_ptr<base> &b1)
    {
        cout << "\n copy ctr called";
        this->data = b1->data;
    }

    base(const base &b1)
    {
        cout << "\n copy ctr called data: " << b1.data << endl;
        this->data = b1.data;
    }
    // copy ctr ends here

    string &getData()
    {
        return data;
    }

    void setData(string str)
    {
        data = str;
    }

    // move ctrs begins
    explicit base(unique_ptr<base> &&b1)
    {
        cout << "\n move ctr called...";
        data = b1->data;
        b1->data = "";
    }

    base(base &&b1)
    {
        cout << "\n move ctr called...";
        data = b1.data;
        b1.data = "";
    }
    // move ctr ends

    // assignment operator begins
    base &operator=(unique_ptr<base> &&b1)
    {
        cout << "\n move assgnmt opt called..";
        if (this != b1.get())
        {
            data = b1->data;
            b1->data = "";
        }
        return *this;
    }

    base &operator=(const base &b1)
    {
        if (this != &b1)
        {
            cout << "\n assgnmt opt called...";
            data = b1.data;
        }
        return *this;
    }
    // assignment operator ends

    ~base()
    {
        cout << "\n deleting = " << data;
    }
};

void UniquePtrWithVectors()
{
    vector<unique_ptr<base>> myVec;

    auto b1 = make_unique<base>("Neo");
    auto b2 = make_unique<base>("Trinity");
    auto b3 = make_unique<base>("Morpheus");

    myVec.push_back(move(b1));
    myVec.push_back(move(b2));
    myVec.push_back(move(b3));
    // myVec.emplace_back(make_unique<base>("Hello"));

    // unqiue pointer will be always passed as reference
    for (const auto &itr : myVec)
    {
        itr->printVal();
    }
}

// return value becomes an rvalue, thus no separate move required from caller in case of unique_ptr
unique_ptr<base> UniquePtrWidValue(unique_ptr<base> ptr)
{
    ptr->setData("Hello Neo");
    return ptr;
}

// return lvalue, thus move is required in case of unique_ptr caller
unique_ptr<base> &UniquePtrWidRef(unique_ptr<base> &ptr)
{
    ptr.reset(new base("hello neo"));
    return ptr;
}

unique_ptr<base> &UniquePtrWidPtr(unique_ptr<base> *ptr)
{
    ptr->reset(new base("hello neo"));
    return *ptr;
}

shared_ptr<base> SharedPtrWidValue(shared_ptr<base> ptr)
{
    ptr->setData("Hello Neo");
    return ptr;
}

// return lvalue, thus move is required in case of unique_ptr caller
shared_ptr<base> &SharedPtrWidRef(shared_ptr<base> &ptr)
{
    ptr.reset(new base("hello neo"));
    return ptr;
}

void SharedPtrWidRefNoReturn(shared_ptr<base> &ptr)
{
    ptr.reset(new base("hello neo"));
}

shared_ptr<base> &SharedPtrWidPtr(shared_ptr<base> *ptr)
{
    ptr->reset(new base("hello neo"));
    return *ptr;
}

int main()
{

    // Unique pointer starts here

#if 0
    // UniquePtrWithVectors();
    auto start = high_resolution_clock::now();

    auto p1 = make_unique<base>("Neo");
    // auto p2 = move(UniquePtrWidRef(p1));
    // auto p2 = UniquePtrWidValue(move(p1));
    auto p2 = move(UniquePtrWidPtr(&p1));

    if (!p1)
    {
        cout << "\n pointing to null now...";
    }
    else
    {
        p1->printVal();
    }

    p2->printVal();

    auto stop = high_resolution_clock::now();

    cout << "\n\n elapsed time: " << duration_cast<microseconds>(stop - start).count();
    // Unique pointer ends here
#endif

    // Shared pointer starts here
    auto start = high_resolution_clock::now();

    auto p1 = make_shared<base>("Neo");

    cout << "\n\n before p1 count: " << p1.use_count();
    SharedPtrWidRefNoReturn(p1);
    // auto p2 = SharedPtrWidValue(p1);

    cout << "\n\n after p1 count: " << p1.use_count();
    // cout << "\n\n after p2 count: " << p2.use_count();
    // auto p2 = move(UniquePtrWidPtr(&p1));

    if (!p1)
    {
        cout << "\n pointing to null now...";
    }
    else
    {
        p1->printVal();
    }

    // p2->printVal();

    auto stop = high_resolution_clock::now();

    cout << "\n\n elapsed time: " << duration_cast<microseconds>(stop - start).count();

    return 0;
}