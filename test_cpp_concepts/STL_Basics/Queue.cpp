#include <iostream>
#include <queue>
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
    queue<unique_ptr<Items>> itemQueue;
    itemQueue.push(make_unique<Items>("Item 1"));
    itemQueue.push(make_unique<Items>("Item 2"));
    itemQueue.push(make_unique<Items>("Item 3"));
    itemQueue.push(make_unique<Items>("Item 4"));
    itemQueue.push(make_unique<Items>("Item 5"));

    cout << "Total items in queue: " << itemQueue.size() << "\n\n";
    int len = itemQueue.size();

    for (size_t i = 0; i < len; i++)
    {
        cout << "Front item in queue:\n";
        itemQueue.front()->display();
        itemQueue.pop();
    }

    cout << " size now after pop " << itemQueue.size() << "\n\n";
    return 0;
}