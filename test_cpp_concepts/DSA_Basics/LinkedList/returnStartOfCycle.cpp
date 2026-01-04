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

struct node *returnStartOfCycle(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;

    // Detect loop
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL; // No cycle

    // Find start of cycle
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // Start of cycle
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
    ninth->next = first; // Create cycle

    struct node *head = first;

    struct node *loopStart = returnStartOfCycle(head);
    if (loopStart != NULL)
    {
        cout << "Start of cycle data: " << loopStart->data << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    // Break cycle before deleting
    ninth->next = NULL;
    deleteList(head);
    return 0;
}