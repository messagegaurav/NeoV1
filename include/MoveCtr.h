//Move Contructor header
#include <iostream> 
#include <vector> 

class MoveCtr
{
    public: 

        MoveCtr(int val);        
        MoveCtr(const MoveCtr& obj);
        //MoveCtr(const MoveCtr&& obj);
        ~MoveCtr();
        inline void show_val()
        {
            std::cout << "this data " << this->data << "\n";
        }

    private: 
        int* data;
};

void create_objects();
