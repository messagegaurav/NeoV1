#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

Node *mergeSortedList(Node *L1, Node *L2)
{
    if (!L1)
        return L2;
    if (!L2)
        return L1;

    Node dummy(0);
    Node *temp = &dummy;

    while (L1 && L2)
    {
        if (L1->data < L2->data)
        {
            temp->next = L1;
            L1 = L1->next;
        }
        else
        {
            temp->next = L2;
            L2 = L2->next;
        }
        temp = temp->next;
    }
    temp->next = L1 ? L1 : L2;
    return dummy.next;
}

// Helper to print the list
void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

// Helper to free memory
void deleteList(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *root = new Node(1);
    root->next = new Node(4);
    root->next->next = new Node(6);
    root->next->next->next = new Node(8);
    root->next->next->next->next = nullptr;

    Node *head = new Node(2);
    head->next = new Node(5);
    head->next->next = new Node(7);
    head->next->next->next = nullptr;

    Node *final = mergeSortedList(root, head);

    printList(final);

    deleteList(final);
    cout << endl;
    return 0;
}