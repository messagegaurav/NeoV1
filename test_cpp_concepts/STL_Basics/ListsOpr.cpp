#include <iostream>
#include <list>
#include <string>

using namespace std;

void simpleList()
{
    list<int> myList = {10, 20, 30, 40, 50};
    cout << "Initial list elements: " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }
    cout << "\n\n";

    myList.push_back(60);
    myList.push_front(5);
    cout << "After push_back and push_front: " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }
    myList.pop_back();
    myList.pop_front();
    cout << "After pop_back and pop_front: " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }

    myList.insert(next(myList.begin(), 2), 25);
    cout << "After inserting 25 at index 2: " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }

    myList.erase(next(myList.begin(), 4));
    cout << "After erasing element at index 4: " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }

    myList.reverse();
    cout << "After reversing the list: " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }

    myList.sort();
    cout << "After sorting the list: " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }

    myList.splice(next(myList.begin(), 2), list<int>{70, 80, 90});
    cout << "After splicing another list at the beginning: " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }

    auto itr = myList.begin();
    advance(itr, 3);
    int value = *itr;
    myList.erase(itr);
    cout << "After removing element with value " << value << ": " << "\n \n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }

    myList.push_back(20);
    myList.push_back(30);
    myList.sort();
    myList.unique();
    cout << "After adding duplicates and applying unique(): " << "\n\n";
    for (const auto &item : myList)
    {
        cout << item << " ";
    }
}

int main()
{
    simpleList();
    return 0;
}