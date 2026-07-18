#include <iostream>

using namespace std;

/* Remove all duplicate nodes from the list along
with its original entry for e.g if its 1, 2, 2, 3 Output should be
1, 3 */

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

Node *remDuplicates(Node *root)
{
    if (root == nullptr)
        return nullptr;
    Node *head = root;
    Node *prev = nullptr, *fwd = nullptr;
    bool isDup = false;

    while ((head != nullptr) && (head->next != nullptr))
    {
        while (head->data == head->next->data)
        {
            // if matches delete the current node
            fwd = head->next;
            Node *temp = head;
            delete temp;
            head = fwd;
            isDup = true;
        }
        // delete the current node
        if (isDup)
        {
            prev->next = head->next;
            Node *temp1 = head;
            head = prev->next;
            delete temp1;
            isDup = false;
        }
        else
        {
            prev = head;
            head = head->next;
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(2);
    root->next->next->next = new Node(2);
    root->next->next->next->next = new Node(2);
    root->next->next->next->next->next = new Node(3);
    root->next->next->next->next->next->next = new Node(3);
    root->next->next->next->next->next->next->next = new Node(4);
    root->next->next->next->next->next->next->next->next = nullptr;

    remDuplicates(root);
    Node *start = root, *head = root;
    while (start != nullptr)
    {
        cout << start->data << " ";
        start = start->next;
    }
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    cout << endl;
    return 0;
}