#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Data
{
private:
    int value;

public:
    explicit Data(int dt) : value(dt) {}
    [[nodiscard]] int get() const { return value; }
    void set(int val) { value = val; }
    void display() const { cout << "val: " << value << endl; }
};

class DataManager
{
private:
    vector<unique_ptr<Data>> storeData;

public:
    [[nodiscard]] size_t store(unique_ptr<Data> data)
    {
        storeData.emplace_back(move(data));
        return storeData.size() - 1;
    }

    [[nodiscard]] Data *get(size_t index) const
    {
        return index < storeData.size() ? storeData[index].get() : nullptr;
    }

    void modify(size_t index, int value)
    {
        if (auto *data = get(index))
        {
            cout << "Setting value !!!" << endl;
            data->set(value);
        }
    }

    void display(size_t index) const
    {
        if (index < storeData.size())
        {
            auto data = get(index);
            data->display();
        }
    }

    void displayAll() const
    {
        for (const auto &ch : storeData)
        {
            ch->display();
        }
    }
};

int main()
{
    DataManager manager;
    size_t id1 = manager.store(make_unique<Data>(100));
    size_t id2 = manager.store(make_unique<Data>(200));

    manager.display(id1);
    manager.display(id2);

    manager.modify(id1, 150);
    manager.modify(id2, 250);

    if (auto *data1 = manager.get(id1))
        data1->display();

    if (auto *data2 = manager.get(id2))
        data2->display();

    manager.displayAll();

    return 0;
}