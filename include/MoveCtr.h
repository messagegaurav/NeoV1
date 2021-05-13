//Move Contructor header
#include <iostream>
#include <vector>

class CppConcept
{
public:
    CppConcept(int val);
    CppConcept(const CppConcept &obj);
    //MoveCtr(const MoveCtr&& obj);
    ~CppConcept();

    inline void show_val()
    {
        std::cout << "\n this data " << *this->data << "\n";
    }

    // Static function of how to call static private member
    static CppConcept fun()
    {
        return CppConcept(0);
    }

    //Static funciton calling static member
    static void show_count(CppConcept *sMc)
    {
        std::cout << "\n default Ctr count = " << sMc->mdefCtrCount << "\n";
        std::cout << "\n Copy Ctr count = " << sMc->mCopyCtrCount << "\n";
        std::cout << "\n Destructor count = " << sMc->mDestCount << "\n";
    }

    static int setValue(int j)
    {
        mdefCtrCount = j;
        return mdefCtrCount;
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
