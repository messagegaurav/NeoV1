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

CppConcept::CppConcept(const CppConcept &&obj)
{
    cout << "\n Called Move Constructor\n\n";
    this->data = new int;
    *this->data = 0;
}

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
    cout << "\n\n Smart pointer with Vector";
    //GA: 1st scenario when using raw heap pointers in vector call delete explicitly to avoid leak or SIGSEGV
    {
        cout << "\n 1st scenario ";

        CppConcept *obj1 = new CppConcept(100);
        cout << "\n obj adr " << &obj1;
        vector<CppConcept *> myVec;
        // myVec.push_back(move(*obj1));
        myVec.push_back(obj1);
        cout << "\n obj adr " << &myVec[0];
        myVec[0]->show_val();
        delete obj1;
        myVec.clear();
    }

    //GA: 2nd scenario using the smart pointers with vector to avoid using delete
    {
        cout << "\n\n 2nd scenario ";

        vector<unique_ptr<CppConcept>> myVec;
        unique_ptr<CppConcept> up1 = make_unique<CppConcept>(200);
        // myVec.push_back(move(up1));
        // myVec[0]->show_val();
        if (!up1)
        {
            cout << "\n\n Since its moved to vector, it now contains null";
        }
        else
        {
            cout << "\n pushing refrence of unique ptr to vector, thus contains valid data";
            PlayWithSmartPtr(up1);

            if (up1.get() != nullptr)
            {
                up1->show_val();
                cout << "\n passed by ref, now passed unique ptr will disown and will be null";
            }
        }
        myVec.clear();
    }

    //GA: shared pointer unlike unique ptr waits for ref count to get 0 for calling delete not when scope ends
    {
        cout << "\n\n 3rd scenario ";

        vector<shared_ptr<CppConcept>> myVec;
        {
            auto sp1 = make_shared<CppConcept>(200);
            {
                auto sp2 = sp1;
                myVec.push_back(move(sp2));
                cout << "\n shared ptr ref count = " << sp1.use_count();
            }
        }
        myVec[0]->show_val();
    }
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

auto RetSmartPtr(unique_ptr<CppConcept> up1)
{
    cout << "\n\nMethod: " << __FUNCTION__;
    up1->set(400);
    up1->show_val();
    return up1;
}

void PlayWithSmartPtr(unique_ptr<CppConcept> &temp)
{
    cout << "\n\n Call:  " << __FUNCTION__;
    temp->show_val();
    unique_ptr<CppConcept> temp1 = make_unique<CppConcept>(500);
    temp1->show_val();
    temp1 = RetSmartPtr(move(temp));
    temp1->show_val();
}