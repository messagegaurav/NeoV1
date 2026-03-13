#include <iostream>
#include <mutex>
#include <memory>
using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Instance Created..!!!";
    }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton(Singleton &&other) = delete;
    Singleton &operator=(Singleton &&other) = delete;
    // static Singleton *instance;
    static unique_ptr<Singleton> instance;

public:
    static mutex mtx;
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
            {
                // instance = new Singleton();
                instance = unique_ptr<Singleton>(new Singleton());
                // instance = unique_ptr<Singleton>(new Singleton());
            }
        }
        return instance.get();
    }
    ~Singleton()
    {
        cout << "Destroyed..!!!" << endl;
    }
    // static void destroy()
    // {
    //     lock_guard<mutex> lock(mtx);
    //     if (instance != nullptr)
    //     {
    //         delete instance;
    //         instance = nullptr;
    //     }
    // }

    void show()
    {
        cout << "Yuppy show on..!!!" << endl;
    }
};

mutex Singleton::mtx;
// Singleton *Singleton::instance = nullptr;
unique_ptr<Singleton> Singleton::instance = nullptr;

int main()
{
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    if (p1 == p2)
    {
        cout << "Yes Singleton..>!!!!" << endl;
        p1->show();
    }
    else
        cout << "Not Singleton...!!!" << endl;
    // Singleton::destroy();
    return 0;
}