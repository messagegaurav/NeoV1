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

struct node *mergeTwoSortedLists(struct node *L1, struct node *L2)
{
    if (L1 == NULL)
        return L2;
    if (L2 == NULL)
        return L1;
    if (L1->data < L2->data)
    {
        L1->next = mergeTwoSortedLists(L1->next, L2);
        return L1;
    }
    else
    {
        L2->next = mergeTwoSortedLists(L1, L2->next);
        return L2;
    }
}

int main()
{
    // Create first sorted list: 1, 3, 5
    struct node *l1_1 = new node();
    struct node *l1_2 = new node();
    struct node *l1_3 = new node();
    l1_1->data = 1;
    l1_1->next = l1_2;
    l1_2->data = 3;
    l1_2->next = l1_3;
    l1_3->data = 5;
    l1_3->next = NULL;

    // Create second sorted list: 2, 4, 6
    struct node *l2_1 = new node();
    struct node *l2_2 = new node();
    struct node *l2_3 = new node();
    l2_1->data = 2;
    l2_1->next = l2_2;
    l2_2->data = 4;
    l2_2->next = l2_3;
    l2_3->data = 6;
    l2_3->next = NULL;

    struct node *merged = mergeTwoSortedLists(l1_1, l2_1);

    struct node *temp = merged;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    deleteList(merged);
    return 0;
}