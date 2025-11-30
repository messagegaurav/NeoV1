#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

#define SECA 0
#define SECB 1

// simply using vector with built in data type
// void simpleVector()
// {
//     vector<int> vec = {1, 2, 3};
//     vec.push_back(4);
//     vec.push_back(5);
//     vec.push_back(6);
//     vec.push_back(7);
//     cout << "vec.size " << vec.size() << "\t capacity: " << vec.capacity() << "\n\n";

// #if SECB
//     try
//     {
//         vec.shrink_to_fit();
//         cout << "After shrink_to_fit, capacity: " << vec.capacity() << "\n\n";
//         vec.at(10) = 100; // out of bounds access
//     }
//     catch (const exception &e)
//     {
//         cerr << "Exception caught: " << e.what() << '\n';
//     }
// #endif

//     vec.front() = 100;
//     vec.back() = 200;

//     vec.insert(vec.begin() + 4, 150); // insert 150 at index 4
//     vec.erase(vec.begin() + 2);       // erase element at index 2

//     for (const auto &item : vec)
//     {
//         cout << item << " ";
//     }
//     cout << "\n\n";
//     vec.clear();
//     if (vec.empty())
//     {
//         cout << "Vector is empty now." << "\n\n";
//     }
//     cout << "After clear, vec.size: " << vec.size() << "\n\n";
// }

class VecClass
{
private:
    int id;
    string name;

public:
    VecClass(int i, string n) : id(i), name(n) { cout << "VecClass with id: " << id << " constructed.\n"; }
    ~VecClass()
    {
        cout << "VecClass with id: " << id << " destroyed.\n";
    }
    VecClass(const VecClass &other) : id(other.id), name(other.name)
    {
        cout << "VecClass with id: " << id << " copy constructed.\n";
    }

    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << "\n";
    }
};

void UsingVecWithHeap()
{
    vector<VecClass *> vecObj;
    vecObj.emplace_back(new VecClass(1, "ObjectOne"));
    vecObj.push_back(new VecClass(2, "ObjectTwo"));

    for (const auto &obj : vecObj)
    {
        obj->display();
    }

    for (auto &obj : vecObj)
    {
        delete obj; // free allocated memory
    }
    vecObj.clear();
}

void UsingVecWithStack()
{
    vector<VecClass> vecObj;
    vecObj.emplace_back(3, "ObjectThree");
    // vecObj.push_back(VecClass(4, "ObjectFour"));

    for (const auto &obj : vecObj)
    {
        obj.display();
    }

    vecObj.clear(); // automatic cleanup of stack objects
}

void UsingSmartPtr()
{
    class VecSmartPtr
    {
    private:
        int id;
        string name;

    public:
        VecSmartPtr(int i, string n) : id(i), name(n)
        {
            cout << "VecSmartPtr with id: " << id << " constructed.\n";
        }
        ~VecSmartPtr()
        {
            cout << "VecSmartPtr with id: " << id << " destroyed.\n";
        }
        VecSmartPtr(const VecSmartPtr &other) : id(other.id), name(other.name)
        {
            cout << "VecSmartPtr with id: " << id << " copy constructed.\n";
        }

        VecSmartPtr(VecSmartPtr &&other) noexcept : id(other.id), name(move(other.name))
        {
            cout << "VecSmartPtr with id: " << id << " move constructed.\n";
            other.id = 0;
            other.name = "";
        }

        VecSmartPtr &operator=(VecSmartPtr &&other) noexcept
        {
            if (this != &other)
            {
                id = other.id;
                name = move(other.name);
                cout << "VecSmartPtr with id: " << id << " move assigned.\n";
                other.id = 0;
                other.name = "";
            }
            return *this;
        }

        void display() const
        {
            cout << "ID: " << id << ", Name: " << name << "\n";
        }
    };

    vector<unique_ptr<VecSmartPtr>> vecSmartPtr;
    vecSmartPtr.emplace_back(make_unique<VecSmartPtr>(5, "SmartObjectFive"));

    for (auto const &obj : vecSmartPtr)
    {
        obj->display();
    }
}

int main()
{
    // simpleVector();
    // UsingVecWithHeap();
    cout << "\n";
    // UsingVecWithStack();
    UsingSmartPtr();

    return 0;
}