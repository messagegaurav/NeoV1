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

struct node *revKthGroup(struct node *curr, int k)
{
    struct node *prev = NULL, *next = NULL;
    struct node *temp = curr;
    int count = 0;

    while (temp != NULL && count < k)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        count++;
    }

    if (next != NULL)
    {
        curr->next = revKthGroup(next, k);
    }

    return prev;
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

    head = revKthGroup(head, 6);

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