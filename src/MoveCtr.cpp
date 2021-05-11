#include <MoveCtr.h>

using namespace std;

int MoveCtr::mdefCtrCount = 0;
int MoveCtr::mCopyCtrCount = 0;
int MoveCtr::mDestCount = 0;

MoveCtr::MoveCtr(int val)
{
    data = new int;
    *data = val;
    mdefCtrCount++;
}

MoveCtr::MoveCtr(const MoveCtr &obj)
{
    this->data = new int;
    this->data = obj.data;
    mCopyCtrCount++;
}

// MoveCtr::MoveCtr(const MoveCtr&& obj)
// {
//     cout << "Called Move Constructor\n\n";
//     this->data = new int;
//     this->data = 0;
// }

MoveCtr::~MoveCtr()
{
    mDestCount++;
    // delete data;
}

void create_objects()
{
    // Checking constructor and destructor calls with Vector
    {
        vector<MoveCtr> myVec;
        MoveCtr obj2(10);
        MoveCtr obj3(20);
        myVec.reserve(2);
        // obj1.push_back(MoveCtr(10));
        // obj1.push_back(MoveCtr(20));
        myVec.push_back(obj2);
        myVec.push_back(obj3);
        // myVec.reserve(3);
        // myVec.emplace_back();
        // myVec.emplace_back();
        // myVec.emplace_back();

        for (auto itr : myVec)
        {
            itr.show_val();
        }
    }
    MoveCtr sMC = MoveCtr::fun();
    sMC.show_count(&sMC);
}