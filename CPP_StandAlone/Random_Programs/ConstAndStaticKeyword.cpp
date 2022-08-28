/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-29 22:11:16
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-29 22:26:14
 */

#include <iostream>

using namespace std;

class StaticOperations
{
    int data;
    static int staticData;

public:
    StaticOperations(int _x, int _y)
    {
        data = _x;
        staticData = _y;
    }
    void printVal()
    {
        cout << "\n data: " << data << "      staticData: " << staticData;
    }
    static void staticFunction(int _data)
    {
        staticData = _data;
    }
};

class ConstOperations
{
private:
    int data;
    mutable int constData;

public:
    ConstOperations(const int _data) : constData(_data)
    {
    }

    void setData(const int _data)
    {
        data = _data;
    }
    void setConstData(const int _data) const
    {
        constData = _data;
        cout << "\n " << __FUNCTION__ << " :constData: " << constData;
    }
    void printVal()
    {
        cout << "\n data: " << data << "      constData: " << constData;
    }
};

int StaticOperations::staticData;

int main()
{
    static StaticOperations s1(10, 20);

    s1.printVal();

    s1.staticFunction(40);

    s1.printVal();

    // const operations
    cout << "\n\n";

    const ConstOperations c1(15);
    c1.setConstData(20);

    ConstOperations *c2 = const_cast<ConstOperations *>(&c1);
    int i = 40;
    c2->setData((int &&)i);
    c2->printVal();

    cout << "\n\n";

    return 0;
}