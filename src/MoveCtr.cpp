#include <MoveCtr.h>

using namespace std;

MoveCtr::MoveCtr(int val)
{
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
    delete data;
}