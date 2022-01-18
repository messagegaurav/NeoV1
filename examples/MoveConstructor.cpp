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
        *this->m_data = *m1.m_data;
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

private:
    int m_size;
    char *m_data;
};

int main()
{
    Moved m1("Helloeo");
    Moved m2(m1);

    Moved m3(std::move(m2));

    Moved m4("Gaurav");

    // m4 = (std::move(m3));

    cout << "\n\n";

    return 0;
}