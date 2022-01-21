/*
 * Created on Tue Jan 18 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Moved
{
public:
    Moved(const char *str)
    {

        m_data = new char[sizeof(str)];
        m_size = sizeof(str);
        strcpy(m_data, str);
        cout << "\n default ctr val = " << m_data;
    }
    Moved(const Moved &m1)
    {
        this->m_size = sizeof(m1.m_data);
        this->m_data = new char[this->m_size];
        strcpy(this->m_data, m1.m_data);
        cout << "\n copy ctr m_size  = " << m_size << "  m_data = " << m_data;
    }
    Moved(Moved &&m1)
    {
        this->m_size = m1.m_size;
        this->m_data = m1.m_data;
        cout << "\n Moved ctrr size = " << m_size << " m_data = " << m_data;
        m1.m_size = 0;
        m1.m_data = nullptr;
    }

    Moved &operator=(Moved &&m1)
    {
        delete m_data;
        this->m_size = m1.m_size;
        this->m_data = m1.m_data;
        m1.m_size = 0;
        m1.m_data = nullptr;
        cout << "\n Moved assignment oprt size = " << this->m_size << " m_data = " << this->m_data;
        return *this;
    }

    void printVal()
    {
        cout << " \n m_size = " << m_size << "  m_data" << m_data;
    }

    ~Moved()
    {
        cout << "\n destructing ....";
        delete m_data;
    }
    char *getData()
    {
        return m_data;
    }

private:
    int m_size;
    char *m_data;
};

int main()
{

    vector<Moved *> myVec;

    Moved *m1 = new Moved("Neo");

    Moved *m2 = new Moved("Tri");

    myVec.push_back(m1), myVec.push_back(m2);
    auto itr1 = std::find_if(myVec.begin(), myVec.end(), [](Moved *a)
                             { a->printVal(); if(!strcmp(a->getData(), "Neo")) {cout<<"\n found the object to be removed"; return true;} else {
            return false;
        } });

    // myVec.erase(std::remove(myVec.begin(), myVec.end(), itr1), myVec.end());
    // cout << "\n found object: " << itr1->
    myVec.erase(itr1);

    cout << "\n size of vec: " << myVec.size();
    for (auto itr : myVec)
    {
        cout << "\n I am in";
        itr->printVal();
    }

    // delete m1;
    // delete m2;

    cout << "\n\n";

    return 0;
}