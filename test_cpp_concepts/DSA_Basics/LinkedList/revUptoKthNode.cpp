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

struct node *head = NULL;

void revUptoKthNode(struct node *curr, int k)
{
    struct node *prev, *next = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        printf("Reversing up to K: current node data = %d, count = %d\n", curr->data, count);
        next = curr->next; // save next node
        curr->next = prev; // reverse the link
        prev = curr;       // move prev to current node
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        printf("Connecting reversed part to next node with data = %d\n", next->data);
        head->next = next; // connect the last node of reversed part to the next part
    }
    head = prev; // update head to new first node
    printf("Reversed up to K nodes. New head data = %d\n", head->data);
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

    head = first;

    revUptoKthNode(head, 2);

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