#include <MoveCtr.h>

using namespace std;

int CppConcept::mdefCtrCount = 0;
int CppConcept::mCopyCtrCount = 0;
int CppConcept::mDestCount = 0;

CppConcept::CppConcept(int val)
{
    data = new int;
    *data = val;
}

CppConcept::CppConcept(const CppConcept &obj)
{
    this->data = new int;
    this->data = obj.data;
}

// MoveCtr::MoveCtr(const MoveCtr&& obj)
// {
//     cout << "Called Move Constructor\n\n";
//     this->data = new int;
//     this->data = 0;
// }

CppConcept::~CppConcept()
{
    // delete data;
}

void VectorGame()
{
    // Checking constructor and destructor calls with Vector
    {
        vector<CppConcept> myVec;
        CppConcept obj2(10);
        CppConcept obj3(20);
        myVec.reserve(2);
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

    cout << "\n";
}

void StaticGame()
{
    CppConcept obj1(10);
    int t = CppConcept::setValue(obj1.setValue(300));

    // static object to call static private member
    CppConcept sMC = CppConcept::fun();
    sMC.show_count(&sMC);

    cout << "\n private static member set = " << t << "\n";
}