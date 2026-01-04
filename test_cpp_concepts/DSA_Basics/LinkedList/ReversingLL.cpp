#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// Function to delete all nodes in the linked list
void deleteList(struct node *&head)
{
    while (head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        delete temp;
    }
}
struct node *head = NULL;
void revLinkedList(struct node *curr)
{
    struct node *prev, *next = NULL;
    while (curr != NULL)
    {
        printf("Reversing: current node data = %d\n", curr->data);
        next = curr->next; // save next node
        curr->next = prev; // reverse the link
        prev = curr;       // move prev to current node
        curr = next;
    }
    head = prev; // update head to new first node
    printf("Linked list reversed. New head data = %d\n", head->data);
}

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

bool findLoop(struct node *head)
{
    // slow and fast pointer approach
    // move slow by 1 and fast by 2
    // if any point slow == fast then loop exists
    // else if fast or fast->next becomes NULL then no loop

    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
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

bool checkPalindrome(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;

    stack<int> s;
    while (fast != NULL && fast->next != NULL)
    {
        s.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL)
    {
        slow = slow->next;
    }
    while (slow != NULL)
    {
        int top = s.top();
        s.pop();
        if (top != slow->data)
            return false;
        slow = slow->next;
    }
    return true;
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
    // revLinkedList(head);

    // revUptoKthNode(head, 2);
    // head = revKthGroup(head, 6);

    // struct node *temp = head;
    // while (temp != NULL)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }
    // cout << endl;

    // cout << "Loop detected: " << (findLoop(head) ? "Yes" : "No") << endl;
    // struct node *loopStart = returnStartOfCycle(head);
    // if (loopStart != NULL)
    // {
    //     cout << "Start of cycle data: " << loopStart->data << endl;
    // }
    // else
    // {
    //     cout << "No cycle detected." << endl;
    // }

    removeNthNode(head, 3);
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    deleteList(head);
    return 0;
}