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

node *mergeSortedList(node *head1, node *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    node *dummy = new node(0);
    node *tail = dummy;

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = (head1 != nullptr) ? head1 : head2;
    node *mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

int main()
{
    node *ptr1 = new node(1);
    ptr1->next = new node(3);
    ptr1->next->next = new node(5);
    ptr1->next->next->next = new node(7);
    ptr1->next->next->next->next = new node(9);
    ptr1->next->next->next->next->next = nullptr;

    node *ptr2 = new node(2);
    ptr2->next = new node(4);
    ptr2->next->next = new node(8);
    ptr2->next->next->next = nullptr;

    node *temp = mergeSortedList(ptr1, ptr2);

    displayList(temp);
    // deleteList(ptr1);
    // deleteList(ptr2);
    // deleteList(temp);

    cout << "\n";
    return 0;
}