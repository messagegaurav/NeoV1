#include <MoveCtr.h>

using namespace std;

MoveCtr::MoveCtr(int val)
{
    cout << "default constructor called\n";
    data = new int;
    *data = val;
}

MoveCtr::MoveCtr(const MoveCtr& obj)
{
    cout << "Called Copy constructor\n\n";
    this->data = new int;
    this->data = obj.data;
}

// MoveCtr::MoveCtr(const MoveCtr&& obj)
// {
//     cout << "Called Move Constructor\n\n";
//     this->data = new int;
//     this->data = 0;
// }

MoveCtr::~MoveCtr()
{
    cout << "Destructor called\n\n";
    // delete data;
}

void create_objects()
{
    // Checking constructor and destructor calls with Vector
    vector<MoveCtr> obj1;
    MoveCtr obj2(10);
    MoveCtr obj3(20);
    obj1.reserve(2);
    // obj1.push_back(MoveCtr(10));
    // obj1.push_back(MoveCtr(20));
    obj1.push_back(obj2);
    obj1.push_back(obj3);
    // obj1.reserve(3);
    // obj1.emplace_back();
    // obj1.emplace_back();
    // obj1.emplace_back();
}