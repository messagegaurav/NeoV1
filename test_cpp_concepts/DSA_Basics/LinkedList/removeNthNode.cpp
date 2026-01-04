#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void deleteList(struct node *head)
{
    while (head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        delete temp;
    }
}

void removeNthNode(struct node *head, int n)
{
    // slow and fast pointer approach
    // move fast by n nodes
    struct node *slow = head;
    struct node *fast = head;
    for (int i = 0; i < n; i++)
    {
        if (fast == NULL)
            return; // n is greater than the length of the list
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // slow is now pointing to the nth node from the end
    struct node *temp = slow->next;
    slow->next = temp->next;
    delete temp;
}

int main()
{
    struct node *first = new node();
    struct node *second = new node();
    struct node *third = new node();
    struct node *fourth = new node();
    struct node *fifth = new node();
    struct node *sixth = new node();
    struct node *seventh = new node();
    struct node *eighth = new node();
    struct node *ninth = new node();

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = sixth;

    sixth->data = 60;
    sixth->next = seventh;

    seventh->data = 70;
    seventh->next = eighth;

    eighth->data = 80;
    eighth->next = ninth;

    ninth->data = 90;
    ninth->next = NULL;

    struct node *head = first;

    removeNthNode(head, 3);

    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    deleteList(head);
    return 0;
}