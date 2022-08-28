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

    Moved &operator=(Moved &&m1)
    {
        if (this != &m1)
        {
            delete m_data;
            this->m_size = m1.m_size;
            this->m_data = m1.m_data;
            m1.m_size = 0;
            m1.m_data = nullptr;
            cout << "\n Moved assignment oprt size = " << this->m_size << " m_data = " << this->m_data;
        }
        return *this;
    }

    Moved(Moved &&m1) noexcept
        : m_data(nullptr), m_size(0)
    {
        // this->m_size = m1.m_size;
        // this->m_data = m1.m_data;
        // cout << "\n Moved ctrr size = " << m_size << " m_data = " << m_data;
        // m1.m_size = 0;
        // m1.m_data = nullptr;

        // else better use move assignment ctr instead if defined for optimal code.
        *this = move(m1);
        cout << "\n Moved ctrr size = " << this->m_size << " m_data = " << this->m_data;
        m1.m_data = nullptr;
        m1.m_size = 0;
    }

    void printVal()
    {
        cout << " \n m_size = " << m_size << "  m_data" << m_data;
    }

    ~Moved()
    {
        cout << "\n destructing ....";
        if (m_data != nullptr)
            delete[] m_data;
    }

private:
    int m_size;
    char *m_data;
};

int main()
{
    Moved m1("Helloeo");
    Moved m2(m1);

    Moved m3(std::move(m2));

    cout << "\n\n";

    return 0;
}