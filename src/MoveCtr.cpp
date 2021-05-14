#include <MoveCtr.h>

using namespace std;

int CppConcept::mdefCtrCount = 0;
int CppConcept::mCopyCtrCount = 0;
int CppConcept::mDestCount = 0;

CppConcept::CppConcept(int val)
{
    cout << "\n calling default ctr";
    data = new int;
    *data = val;
}

CppConcept::CppConcept(const CppConcept &obj)
{
    cout << "\n calling copy ctr";
    this->data = new int;
    *this->data = *obj.data;
}

// MoveCtr::MoveCtr(const MoveCtr&& obj)
// {
//     cout << "Called Move Constructor\n\n";
//     this->data = new int;
//     this->data = 0;
// }

CppConcept::~CppConcept()
{
    cout << "\n calling destructor ";
    //GA: Vector does shallow copy thus you would need to supply delete when using new
    delete data;
}

void VectorGame()
{
    // Checking constructor and destructor calls with Vector
    {
        vector<CppConcept> myVec;

        myVec.reserve(2);

        //GA: creating object and copying them to the vector
        myVec.push_back(CppConcept(10));
        myVec.push_back(CppConcept(20));

        myVec.clear();

        myVec.emplace_back(10);
        myVec.emplace_back(20);

        // Iterator copies the object one at a time when accessing thus calling copy ctr and then destroyes before accessing next one
        for (auto itr : myVec)
        {
            itr.show_val();
        }

        myVec.clear();
    }

    cout << "\n";
}

// How to use smart pointer with vector : what benefits it provides
void VectorWidSmartPointers()
{
    CppConcept *obj1 = new CppConcept(100);
    cout << "\n size of sp0 " << sizeof(obj1);

    {
        unique_ptr<CppConcept> e1(obj1);
        shared_ptr<CppConcept> sp0;
        cout << "\n size of sp0 " << sizeof(*obj1);
        e1->show_val();
    }
    obj1->show_val();
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