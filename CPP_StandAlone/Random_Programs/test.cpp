

#include <vector>
#include <algorithm>
#include <iostream>

// vector of int vector<int> myVec = {0,1,2,3,4...10};

class S
{
private:
    static S *ptr;
    int data;

public:
    static S &getInstance()
    {
        if (ptr == nullptr)
        {

            ptr = new S();
        }
        return *ptr;
    }

    void setData(int _data)
    {
        data = _data;
    }

    int getData()
    {
        return data;
    }
};

S *S::ptr = nullptr;

using namespace std;

int main()
{

    S *ptr;
    ptr = &(S::getInstance());
    ptr->setData(10);
    cout << "\n value: " << ptr->getData();
    cout << "\n\n";
    return 0;
}