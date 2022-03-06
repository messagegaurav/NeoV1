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

using namespace std;
using namespace std::chrono;

class base
{
    string data;

public:
    base(string _str) : data(_str)
    {
        cout << "\n base constructed with: " << data;
    }

    void printVal()
    {
        cout << "\n data: " << data;
    }

    base(const base &b1)
    {
        cout << "\n copy ctr called";
        this->data = b1.data;
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

    base(base &&b1)
    {
        cout << "\n move ctr called...";
        data = b1.data;
        b1.data = "";
    }

    base &operator=(base &&b1)
    {
        cout << "\n move assgnmt opt called..";
        if (this != &b1)
        {
            data = b1.data;
            b1.data = "";
        }
        return *this;
    }

    ~base()
    {
        cout << "\n deleting = " << data;
    }
};

int main()
{
    stack<base *> myStack;

    base *b1 = new base("Gaurav");
    base *b2 = new base("Neo");
    base *b3 = new base("Trinity");

    // myStack.push({"Gaurav"});
    // myStack.push({"Neo"});
    // myStack.push({"Tri"});

    auto start = high_resolution_clock::now();

    time_t myTime = system_clock::to_time_t(start);
    cout << "\n\n start time: " << ctime(&myTime);

    myStack.push(b1);
    myStack.push(b2);
    myStack.push(b3);

    cout << "\n stack size: " << myStack.size();

    for (int i = 0; !myStack.empty(); i++)
    {
        myStack.top()->printVal();
        delete myStack.top();
        myStack.pop();
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n elapsed time: " << duration.count();

    myTime = system_clock::to_time_t(stop);
    cout << "\n\n end time: " << ctime(&myTime);

    cout << "\n\n";
    return 0;
}