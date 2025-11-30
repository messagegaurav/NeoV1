#include <iostream>
#include <memory>
#include <vector>
#include <cstdio>

using namespace std;
#define SECA 0
#define SECB 1

#if SECA
// returning unique ptr from a function (acts as move with make pointer)
class MyClass
{
public:
    MyClass(int value) : value(value)
    {
        cout << "MyClass constructor called with value: " << value << endl;
    }
    ~MyClass()
    {
        cout << "MyClass destructor called for value: " << value << endl;
    }
    unique_ptr<MyClass> display()
    {
        cout << "Value: " << value << endl;
        return make_unique<MyClass>(value + 1);
    }

    int showVal()
    {
        return value;
    }

private:
    int value;
};

#endif

template <typename T>
class UPtr
{
private:
    T *mPtr;

public:
    explicit UPtr(T *ptr = nullptr) : mPtr(ptr)
    {
        cout << "unique pointer constructed... " << "\n\n";
    }

    UPtr(const UPtr &) = delete;
    UPtr &operator=(const UPtr &) = delete;

    ~UPtr()
    {
        cout << "Uptr destroyed" << "\n\n";
        delete mPtr;
    }

    // move operation
    UPtr(UPtr &&other) : mPtr(other.mPtr)
    {
        other.mPtr = nullptr;
    }

    // Move assignment
    UPtr &operator=(const UPtr &&other)
    {
        if (this != other.mPtr)
        {
            delete mPtr;
            mPtr = other.mPtr;
            other.mPtr = nullptr;
        }
        return *this;
    }

    // operator overloading for *
    T &operator*()
    {
        return *mPtr;
    }

    // operator overloading for ->
    T *operator->()
    {
        return mPtr;
    }

    // get operation
    T *get()
    {
        return mPtr;
    }

    // release operation

    T *release()
    {
        T *temp = mPtr;
        mPtr = nullptr;
        return temp;
    }

    // reset operation
    void reset(T *p = nullptr)
    {
        delete mPtr;
        mPtr = p;
    }
};

int main()
{
#if SECB
    {
        UPtr<int> P(new int(20));
        cout << "Value of uP: " << *P << "\n\n";

        UPtr<int> P1 = move(P);
        cout << "new P1 value: " << *P1 << "\n\n";

        if (!P.get())
        {
            cout << "\n I am emtpy now P" << "\n\n";
        }
    }
#endif
#if SECA
    { // simply using reset and release example
        auto ptr1 = make_unique<MyClass>(10);
        MyClass *ptr2 = ptr1.release();
        if (!ptr1)
        {
            cout << "ptr1 is now null after move." << endl;
        }

        cout << "ptr2 points to " << ptr2->showVal() << endl;
        delete ptr2; // Manually delete since we released ownership
        ptr1.reset();
    }
#endif

#if SECA
    {
        vector<unique_ptr<MyClass>> vec;
        vec.push_back(make_unique<MyClass>(10));
        vec.push_back(make_unique<MyClass>(20));
        vec.push_back(make_unique<MyClass>(30));

        MyClass *ptr = vec[0].get();
        ptr->showVal();
        // delete ptr;

        for (auto &item : vec)
        {
            item->showVal();
        }
    }
#endif

#if SECA // move semantics example
    {
        class Resources
        {
        public:
            Resources()
            {
                cout << "Resources acquired." << endl;
            }
            ~Resources()
            {
                cout << "Resources released." << endl;
            }
        };

        class Manager
        {
        public:
            Manager() : resPtr(make_unique<Resources>())
            {
                cout << "Manager created." << endl;
            }
            ~Manager()
            {
                cout << "Manager destroyed." << endl;
            }
            Manager(const Manager &) = delete;
            Manager(Manager &&other) noexcept : resPtr(move(other.resPtr))
            {
                cout << "Manager moved." << endl;
            }

        private:
            unique_ptr<Resources> resPtr;
        };
        Manager mgr1;
        Manager mgr2 = move(mgr1);
    }
#endif // SECB

#if SECA // array example with unique ptr
    {
        unique_ptr<int[]> arrPtr = make_unique<int[]>(5);
        for (int i = 0; i < 5; ++i)
        {
            arrPtr[i] = i * 10;
        }

        for (int i = 0; i < 5; ++i)
        {
            cout << arrPtr[i] << " ";
        }
        cout << endl;
    }
#endif

#if SECA // custom delete for unique ptr
    {
        auto fileDel = [](FILE *fp)
        {
            if (fp)
            {
                cout << "Closing file." << endl;
                fclose(fp);
            }
        };
        {
            unique_ptr<FILE, decltype(fileDel)> fPtr(fopen("text.txt", "w"), fileDel);
            if (fPtr)
            {
                fputs("Hello, World!\n", fPtr.get());
            }
        }
        unique_ptr<FILE, decltype(fileDel)> fPtr2(fopen("text.txt", "r"), fileDel);
        if (fPtr2)
        {
            char buff[256];
            while (fgets(buff, sizeof(buff), fPtr2.get()))
            {
                cout << buff;
            }
        }
        else
        {
            cerr << "Failed to open file for reading." << endl;
        }
    }
#endif

    return 0;
}
