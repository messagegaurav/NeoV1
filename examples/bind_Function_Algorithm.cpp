/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-23 15:27:37
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-23 22:14:53
 */

#ifndef __ALGORITHMS__
#define __ALGORITHMS__

#include <iostream>
#include <functional>
#include <stdio.h>

using namespace std;
using namespace std::placeholders;

// declaring a function callable objest identifier aka function pointer
using fp = std::function<void(int)>;

void fun(int data)
{
    cout << "\n doin some wierd stuff with data: " << data;
}

void testingCallback(fp ptr, int data)
{
    ptr(data);
}

// writing a functor

class myFunctor
{
public:
    void operator()(int data)
    {
        cout << "\n functor called with data: " << data;
    }
};

using funcPointer = std::function<void(int, int)>;

class my2D
{
public:
    void setCallback(funcPointer _fp1)
    {
        drawCallback = _fp1;
    }

    void draw(int x, int y)
    {
        drawCallback(x, y);
    }

private:
    funcPointer drawCallback;
};

class my3D
{
public:
    void draw(int x, int y, int z)
    {
        cout << "\n drawing 3D object with x, y, z as: " << x << " " << y << " " << z;
    }
};

int main()
{
    // testingCallback(&fun, 10);
    // myFunctor func;

    // testingCallback(func, 30);

    // auto myLambda = [](int data)
    // { cout << "\n lamda calling data: " << data; };

    // testingCallback(myLambda, 40);

    my2D draw2D;
    my3D draw3D;

    draw2D.setCallback(bind(&my3D::draw, draw3D, _1, _2, 50)); // binded member function with the params and using it's object

    draw2D.draw(4, 5); // since its binded to draw2D now you can substitute the placeholders

    cout << "\n\n";
}

#endif
