#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int value) : data(value), next(nullptr) {}
};

node *reverse_list(node *head)
{
    node *prev = nullptr, *fwd = nullptr;
    while (head != nullptr)
    {
        fwd = head->next;
        head->next = prev;
        prev = head;
        head = fwd;
    }
    return prev;
}

node *createList()
{
    node *node1 = new node(10);
    node1->next = new node(20);
    node1->next->next = new node(30);
    node1->next->next->next = new node(40);
    node1->next->next->next->next = new node(50);
    node1->next->next->next->next->next = nullptr;
    return node1;
}

void display_list(node *temp)
{
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void deleteList(node *head)
{
    while (head != nullptr)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    node *root = createList();
    display_list(root);
    root = reverse_list(root);
    display_list(root);
    deleteList(root);
    return 0;
}