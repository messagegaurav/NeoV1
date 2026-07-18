#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

Node *findCycleInList(Node *root)
{
    if (root == nullptr)
        return nullptr;

    if (root->next == nullptr)
        return nullptr;

    Node *slow = root, *fast = root;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow == fast)
    {
        slow = root;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return nullptr;
}

int main()
{
    Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = new Node(6);
    root->next->next->next->next->next->next = root->next->next;

    Node *cycleStart = findCycleInList(root);
    if (cycleStart == nullptr)
    {
        cout << "No Cycle exists ...!!!" << endl;
    }
    else
    {
        cout << "Cycle exists at : " << cycleStart->data << endl;
        Node *cur = cycleStart;
        while (cur->next != cycleStart)
            cur = cur->next;
        cur->next = nullptr; // break cycle
    }

    Node *start = root;
    while (start != nullptr)
    {
        Node *temp = start;
        start = start->next;
        delete temp;
    }
    cout << endl;
    return 0;
}