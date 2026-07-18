#include <iostream>

using namespace std;

// class base
// {
// private:
//     char *ptr;

// public:
//     base(const base &other)
//     {
//         ptr = new char;
//     }
//     base &operator=(const base &other)
//     {
//         if (this != &other)
//         {
//             *this->ptr = *(other.ptr);
//         }
//     }
// };

class test
{
    int *p;

public:
    // virtual void fun() {}
};

int main()
{
    test T1;
    cout << sizeof(T1) << "\n";

    char *ptr1 = (char *)malloc(128);
    if (ptr1 == nullptr)
        cout << "no memory allocated for ptr1" << "\n";

    char *ptr2 = (char *)malloc(128);
    if (ptr2 == nullptr)
        cout << "no memory allocated for ptr1" << "\n";

    free(ptr1);
    free(ptr2);
    return 0;
}
