#ifndef __OBJECT_RELATIONS__
#define __OBJECT_RELATIONS__

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/*
* Delegation Concepts
*/
class Shape
{
public:
    virtual double area() = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(int val1, int val2) : height(val1), width(val2) {}
    double area()
    {
        return height * width;
    }

private:
    int height;
    int width;
};

class Circle : public Shape
{
public:
    Circle(double data) : radius(data) {}
    double area()
    {
        return (2 * 3.14 * radius);
    }

private:
    double radius;
};

class Windows
{
public:
    Windows(Shape *s) : shape(s) {}

    double area()
    {
        return shape->area();
    }

private:
    Shape *shape;
};

void delegationMethod();

#endif
