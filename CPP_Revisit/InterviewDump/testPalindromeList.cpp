#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char value) : data(value), next(nullptr) {}
};

bool isPalindrom(Node *root)
{
    if (root == nullptr)
        return true;
    if (root->next == nullptr)
        return true;

    // rev half part
    // put string to temp
    // take further into temp and then match

    Node *prev = nullptr, *fwd = nullptr;
    Node *slow = root, *fast = root;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For odd length, skip the middle node
    if (fast != nullptr)
        slow = slow->next;

    Node *temp = root;
    while (temp != slow)
    {
        fwd = temp->next;
        temp->next = prev;
        prev = temp;
        temp = fwd;
    }
    while ((prev != nullptr) && (slow != nullptr))
    {
        if (prev->data != slow->data)
            return false;
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    Node *root = new Node('a');
    root->next = new Node('d');
    root->next->next = new Node('d');
    root->next->next->next = new Node('a');
    root->next->next->next->next = nullptr;
    // root->next->next->next->next->next = new Node(6);
    // root->next->next->next->next->next->next = root->next->next;

    cout << "Is Palindrome: " << (isPalindrom(root) ? "Yes" : "No") << endl;

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