#include <iostream>

using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Instance created...!!!" << endl;
    }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton(Singleton &&other) = delete;
    Singleton &operator=(Singleton &&other) = delete;

public:
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }
    ~Singleton()
    {
        cout << "Destroyed...!!!" << endl;
    }
    void show()
    {
        cout << "Yuppy show it ...!!!" << endl;
    }
};

int main()
{
    Singleton *S1 = &Singleton::getInstance();
    Singleton *S2 = &Singleton::getInstance();
    if (S1 == S2)
    {
        cout << "Yes its singleton..!!!" << endl;
        S1->show();
    }
    else
        cout << "Not not Singleton..!!!" << endl;
    return 0;
}