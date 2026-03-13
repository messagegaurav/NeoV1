#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    node *next;
    node(int dt) : data(dt), next(nullptr) {}
} NODE;

bool loopInList(NODE *curr)
{
    bool loop = false;
    if (curr == nullptr || curr->next == nullptr)
        return false;
    NODE *slow = nullptr, *fast = nullptr;
    slow = curr;
    fast = curr;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            loop = true;
            break;
        }
    }
    if (loop)
    {
        slow = curr;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        cout << " loop started at: " << slow->data << endl;
    }
    return loop;
}

int main()
{
    NODE *head;
    NODE *n1 = new NODE(10);
    head = n1;
    n1->next = new NODE(20);
    n1->next->next = new NODE(30);
    n1->next->next->next = new NODE(40);
    n1->next->next->next->next = n1;

    NODE *temp = head;
    // while (temp != nullptr)
    // {
    //     cout << " " << temp->data;
    //     temp = temp->next;
    // }

    cout << (loopInList(temp) ? "Loop is there" : "No Loop found") << endl;

    // while (head != nullptr)
    // {
    //     NODE *temp = head->next;
    //     delete head;
    //     head = temp;
    // }

    return 0;
}