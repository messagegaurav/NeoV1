/*
 * Created on Tue Jun 08 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <vector>
#include <memory>
#include <utility>

using namespace std;
class CppConcept
{
public:
    CppConcept(int val);
    CppConcept(const CppConcept &obj);
    CppConcept(const CppConcept &&obj);
    ~CppConcept();

    void show_val()
    {
        cout << "\n data = " << *this->data << "\n";
        // cout << "\n data "
        //           << "\n";
    }

    void show_val() const
    {
        cout << "\n data = " << *this->data << "\n";
    }

    // Static function of how to call static private member
    static CppConcept fun()
    {
        return CppConcept(0);
    }

    //Static funciton calling static member
    static void show_count(CppConcept *sMc)
    {
        cout << "\n default Ctr count = " << sMc->mdefCtrCount << "\n";
        cout << "\n Copy Ctr count = " << sMc->mCopyCtrCount << "\n";
        cout << "\n Destructor count = " << sMc->mDestCount << "\n";
    }

    static int setValue(int j)
    {
        mdefCtrCount = j;
        return mdefCtrCount;
    }

    void set(int data)
    {
        *this->data = data;
    }

private:
    int *data;
    // static variable to check the count
    static int mdefCtrCount;
    static int mCopyCtrCount;
    static int mDestCount;
};

void VectorGame();
void StaticGame();
void VectorWidSmartPointers();
void PlayWithSmartPtr(unique_ptr<CppConcept> &temp);
auto RetSmartPtr(unique_ptr<CppConcept> up1);
