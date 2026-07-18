#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

void reorderList(Node *root)
{
    // find middle of list
    // reverse only second half of list
    // then interleave the list
    if (!root || !root->next)
        return;
    Node *slow = root, *fast = root;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split and reverse second half
    Node *secondHalf = slow->next;
    slow->next = nullptr;

    Node *prev = nullptr, *fwd = nullptr;
    while (secondHalf != nullptr)
    {
        fwd = secondHalf->next;
        secondHalf->next = prev;
        prev = secondHalf;
        secondHalf = fwd;
    }
    Node *revSecondHalfStart = prev;
    Node *interleave = root;
    Node *temp = nullptr;
    while (interleave != nullptr && revSecondHalfStart != nullptr)
    {
        temp = interleave->next;
        interleave->next = revSecondHalfStart;
        Node *dump = revSecondHalfStart->next;
        revSecondHalfStart->next = temp;
        revSecondHalfStart = dump;
        interleave = temp;
    }
}

// Helper to print the list
void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << " -> NULL" << std::endl;
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

    printList(root);

    reorderList(root);

    printList(root);

    deleteList(root);
    cout << endl;
    return 0;
}