/*
 * Created on Tue Jan 18 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <map>
#include <string>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

class base
{
public:
    base(const char *b);

    ~base();

    base(const base &b1) = delete;

    base(base &&b1);

    base &operator=(base &&m1);

    void printVal() const
    {
        cout << "\n value: " << str;
    }

private:
    char *str;
};

base::base(const char *b)
{
    str = new char[sizeof(b)];
    strcpy(str, b);
    cout << "\n constructed ";
}
base::~base()
{
    delete str;
    cout << "\n destructed";
}

// base::base(const base &b1)
// {
//     str = new char[sizeof(b1)];
//     *str = *b1.str;
//     cout << "\n called copy ctr";
// }

base::base(base &&b1)
{
    cout << "\n called move ctr";
    str = b1.str;

    b1.str = nullptr;
}

base &base::operator=(base &&m1)
{
    delete str;
    this->str = m1.str;
    m1.str = nullptr;
    cout << "\n Moved assignment oprt m_data = " << this->str;
    return *this;
}

int main()
{

    base b1("Neo");
    base b2("Tri");
    base b3("Mor");
    // map<int, string> myMap = {{4, "Bug"}};

    // myMap.insert(pair<int, string>(2, "Neo"));
    // myMap.insert(pair<int, string>(1, "Trinity"));
    // myMap[3] = "Morpheous";
    // myMap.insert({5, "Ciphor"});

    // map<int, string>::reverse_iterator itr;

    // for (itr = myMap.rbegin(); itr != myMap.rend(); itr++)
    // {
    //     cout << " \n key: " << itr->first << " value: " << itr->second;
    // }

    map<int, base> myMap;

    myMap.insert(std::make_pair(1, std::move(b1)));
    // myMap.insert({2, b2});
    // myMap.insert({3, b3});
    myMap.insert(std::make_pair(1, std::move(b2)));
    myMap.insert(std::make_pair(1, std::move(b3)));

    for (auto const &itr : myMap)
    {
        itr.second.printVal();
    }

    cout << "\n\n";
    return 0;
}
