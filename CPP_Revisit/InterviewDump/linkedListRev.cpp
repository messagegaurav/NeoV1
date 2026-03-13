#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    node *next;
    node(int dt) : data(dt), next(nullptr) {}
} NODE;

NODE *revList(NODE *curr)
{
    NODE *prev = nullptr;
    NODE *Next;
    while (curr != nullptr)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

int main()
{
    NODE *head;
    NODE *n1 = new NODE(10);
    head = n1;
    n1->next = new NODE(20);
    n1->next->next = new NODE(30);
    n1->next->next->next = new NODE(40);
    n1->next->next->next->next = nullptr;

    NODE *temp = head;
    // while (temp != nullptr)
    // {
    //     cout << " " << temp->data;
    //     temp = temp->next;
    // }

    NODE *ptr = revList(temp);
    head = ptr;
    while (ptr != nullptr)
    {
        cout << " " << ptr->data;
        ptr = ptr->next;
    }

    cout << endl;

    while (head != nullptr)
    {
        NODE *temp = head->next;
        delete head;
        head = temp;
    }

    return 0;
}