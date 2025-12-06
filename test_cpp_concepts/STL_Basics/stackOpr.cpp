#include <iostream>
#include <stack>
#include <memory>

using namespace std;

class Items
{
private:
    string name;

public:
    Items(string n) : name(n)
    {
        cout << "Item Created: " << name << "\n";
    }
    ~Items()
    {
        cout << "Item Destroyed: " << name << "\n";
    }
    void display() const
    {
        cout << "Item Name: " << name << "\n";
    }
    Items(const Items &other) = delete;
    Items &operator=(const Items &other) = delete;
    Items(Items &&other) noexcept : name(move(other.name))
    {
        cout << "Item Moved: " << name << "\n";
    }
    Items &operator=(Items &&other) noexcept
    {
        if (this != &other)
        {
            name = move(other.name);
            cout << "Item Move Assigned: " << name << "\n";
        }
        return *this;
    }
};

int main()
{
    stack<unique_ptr<Items>> itemStock;
    itemStock.push(make_unique<Items>("Item 1"));
    itemStock.push(make_unique<Items>("Item 2"));
    itemStock.push(make_unique<Items>("Item 3"));
    itemStock.push(make_unique<Items>("Item 4"));
    itemStock.push(make_unique<Items>("Item 5"));

    cout << "Total items in stock: " << itemStock.size() << "\n\n";
    int len = itemStock.size();

    for (size_t i = 0; i < len; i++)
    {
        cout << "Top item in stock:\n";
        itemStock.top()->display();
        itemStock.pop();
    }
    return 0;
}
