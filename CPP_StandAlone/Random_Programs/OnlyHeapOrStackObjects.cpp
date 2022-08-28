/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-29 18:40:57
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-29 22:12:01
 */

#include <iostream>
#include <string.h>

using namespace std;

// Only creating heap objects, restricting stack and static objects from creation

class OnlyHeap
{
protected:
    ~OnlyHeap()
    {
        cout << "\n Destructor, called...";
    }
    // OnlyHeap()
    // {

    // }
    const int data;

public:
    OnlyHeap(int _data) : data(_data) { cout << "\n object created.."; }
    void printVal()
    {
        cout << "\n data: " << data;
    }
    void destroy()
    {
        if (this != nullptr)
        {
            delete this;
        }
    }
};

// Only stack objects, preventing heap objects
class OnlyStatic
{
    void *operator new(size_t);
    void *operator new[](size_t);
    int data;

public:
    void setData(int _data)
    {
        data = _data;
    }
    int &getData()
    {
        return data;
    }
};

int main()
{
    OnlyHeap *heap1 = new OnlyHeap(10);
    heap1->printVal();

    heap1->destroy();

    static OnlyStatic staticObj2;
    staticObj2.setData(40);
    cout << "\n obj: " << &staticObj2 << "          data: " << staticObj2.getData();

    OnlyStatic staticObj1 = staticObj2;

    cout << "\n obj: " << &staticObj1 << "          data: " << staticObj1.getData();

    cout << "\n\n";
    return 0;
}