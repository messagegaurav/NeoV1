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
    // Create palindrome list: 1, 2, 3, 2, 1
    struct node *n1 = new node();
    struct node *n2 = new node();
    struct node *n3 = new node();
    struct node *n4 = new node();
    struct node *n5 = new node();

    n1->data = 1;
    n1->next = n2;
    n2->data = 2;
    n2->next = n3;
    n3->data = 3;
    n3->next = n4;
    n4->data = 2;
    n4->next = n5;
    n5->data = 1;
    n5->next = NULL;

    struct node *head = n1;

    cout << "Is palindrome: " << (checkPalindrome(head) ? "Yes" : "No") << endl;

    deleteList(head);
    return 0;
}