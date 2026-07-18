#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

Node *revList(Node *root)
{
    if (root == nullptr)
        return nullptr;
    if (root->next == nullptr)
        return root;

    Node *prev = nullptr, *fwd = nullptr, *head = root;
    while (head != nullptr)
    {
        fwd = head->next;
        head->next = prev;
        prev = head;
        head = fwd;
    }

    return prev;
}

int main()
{
    Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = nullptr;

    Node *start = revList(root);
    Node *ptr = start;
    while (start != nullptr)
    {
        cout << start->data << " ";
        start = start->next;
    }

    while (ptr != nullptr)
    {
        Node *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    cout << endl;
    return 0;
}