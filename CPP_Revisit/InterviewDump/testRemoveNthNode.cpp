#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

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
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    root->next->next->next->next->next = new Node(6);
    root->next->next->next->next->next->next = nullptr;

    int num;
    cout << "Enter Node no to be removed from last: ";
    cin >> num;

    Node dummy(0);
    dummy.next = root;
    Node *slow = &dummy, *fast = &dummy;

    for (int i = 0; i < num; i++)
    {
        if (!fast->next)
        {
            cout << "num out of range" << endl;
            return 1;
        }
        fast = fast->next;
    }
    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp = slow->next;
    slow->next = temp->next;
    delete temp;

    Node *start = dummy.next;

    printList(start);
    deleteList(start);
    cout << endl;
    return 0;
}