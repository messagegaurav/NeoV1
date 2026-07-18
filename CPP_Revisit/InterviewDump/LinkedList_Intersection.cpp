#include <iostream>

using namespace std;

struct node
{
    node(int val) : data(val), next(nullptr) {}
    int data;
    node *next;
};

void deleteList(node *curr)
{
    while (curr != nullptr)
    {
        node *temp = curr->next;
        delete curr;
        curr = temp;
    }
}

void displayList(node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

node *findIntersection(node *head1, node *head2)
{
    if ((head1 == nullptr) || (head2 == nullptr))
        return nullptr;

    node *ptra;
    while (head1 != head2)
    {
        ptra = (head1 == nullptr) ? head2 : head1 = head1->next;
        (head2 == nullptr) ? head1 : head2 = head2->next;
    }
    return ptra;
}

int main()
{
    node *ptr1 = new node(1);
    ptr1->next = new node(2);
    ptr1->next->next = new node(3);
    ptr1->next->next->next = new node(4);
    ptr1->next->next->next->next = new node(5);
    ptr1->next->next->next->next->next = nullptr;

    node *ptr2 = new node(10);
    ptr2->next = new node(20);
    ptr2->next->next = new node(30);
    ptr2->next->next->next = ptr1->next->next->next;

    node *temp = findIntersection(ptr1, ptr2);
    if (temp)
    {
        cout << "Intersection: " << temp->data << "\n";
    }
    return 0;
}