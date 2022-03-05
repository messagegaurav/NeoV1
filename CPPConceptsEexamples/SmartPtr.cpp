/*
 * Created on Fri Jan 21 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <memory>
#include <string.h>

using namespace std;

class base
{
public:
    base(string s) : m_str(s)
    {
        cout << "\nconstructed";
    }
    string &getData()
    {
        return m_str;
    }
    void setData(string s)
    {
        m_str = s;
    }
    ~base()
    {
        cout << "\n destructed now.. ";
    }

private:
    string m_str;
};

int main()
{
    // auto b1 = make_unique<base>("Neo");

    unique_ptr<base> p2;
    // p2 = move(b1);
    base *b2 = new base("Mor");
    p2.reset(b2);
    cout << "\n"
         << p2->getData();

    p2.reset();

    // if (b2)
    //     cout << "\n b2 is valid: " << b2->getData();
    // else
    //     cout << "\n b2 is NULL nw";

    // cout << "\n"
    //      << b1->getData();
    // {
    //     base b2("Tri");
    //     base *b3 = &b2;
    //     cout << "\n"
    //          << b3->getData();

    //     b3 = b1.get();
    //     cout << "\n"
    //          << b3->getData();
    // }

    // if (b1)
    //     cout << "\n after: " << b1->getData();
    // else
    //     cout << "\n i am NULL nw";
    cout << "\n\n";
    return 0;
}