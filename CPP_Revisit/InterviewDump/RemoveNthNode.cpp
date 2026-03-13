#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    node *next;
    node(int dt) : data(dt), next(nullptr) {}
} NODE;

NODE *remNthNode(NODE *curr, int num)
{
    if (curr == nullptr && curr->next == nullptr)
        return curr;

    if (num == 0)
    {
        NODE *newHead = curr->next;
        delete curr;
        return newHead;
    }

    NODE *temp = curr;
    for (int i = 0; i < num - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr)
        return curr; // Invalid position
    cout << "Delete Node: " << temp->next->data << endl;
    NODE *toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return curr;
}

int main()
{
    NODE *head, *start;
    NODE *n1 = new NODE(10);
    head = start = n1;
    n1->next = new NODE(20);
    n1->next->next = new NODE(30);
    n1->next->next->next = new NODE(40);
    n1->next->next->next->next = nullptr;

    NODE *temp = remNthNode(head, 2);
    while (start != nullptr)
    {
        cout << " " << start->data;
        start = start->next;
    }

    // while (head != nullptr)
    // {
    //     NODE *temp = head->next;
    //     delete head;
    //     head = temp;
    // }
    cout << endl;
    return 0;
}