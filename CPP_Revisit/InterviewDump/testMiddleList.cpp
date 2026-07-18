#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

void middleOfList(Node *root)
{
    if (root == nullptr)
        return;
    if (root->next == nullptr)
    {
        cout << "Centre of List: " << root->data << endl;
        return;
    }

    Node *slow = root, *fast = root;
    while ((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Center of List: " << slow->data << endl;
}

int main()
{
    Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = new Node(6);
    root->next->next->next->next->next->next = nullptr;

    middleOfList(root);

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