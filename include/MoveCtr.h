//Move Contructor header
#include <iostream>
#include <vector>

class MoveCtr
{
public:
    MoveCtr(int val);
    MoveCtr(const MoveCtr &obj);
    //MoveCtr(const MoveCtr&& obj);
    ~MoveCtr();
    inline void show_val()
    {
        std::cout << "\n this data " << *this->data << "\n";
    }

    // Static function of how to call static private member
    static MoveCtr fun()
    {
        return MoveCtr(0);
    }

    //Static funciton calling static member
    static void show_count(MoveCtr *sMc)
    {
        std::cout << "\n default Ctr count = " << sMc->mdefCtrCount << "\n";
        std::cout << "\n Copy Ctr count = " << sMc->mCopyCtrCount << "\n";
        std::cout << "\n Destructor count = " << sMc->mDestCount << "\n";
    }

private:
    int *data;
    static int mdefCtrCount;
    static int mCopyCtrCount;
    static int mDestCount;
};

void create_objects();
