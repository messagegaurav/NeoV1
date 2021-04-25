//Move Contructor headers
#include <iostream> 
#include <vector> 

class MoveCtr
{
    public: 

        MoveCtr(int val);
        MoveCtr(const MoveCtr& obj);
        //MoveCtr(const MoveCtr&& obj);
        ~MoveCtr();
    
    private: 
        int* data;
};
