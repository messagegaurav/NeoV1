#include <iostream>

using namespace std;

struct node
{
    node(int val) : data(val), next(nullptr) {}
    int data;
    node *next;
};

bool findCycle(node *curr)
{
    node *slow = curr;
    node *fast = curr;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

node *findStartOfCycle(node *curr)
{
    node *slow = curr;
    node *fast = curr;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = curr;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

node *reverseList(node *curr)
{
    if (curr == nullptr)
        return nullptr;

    node *prev = nullptr;
    while (curr != nullptr)
    {
        node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

void deleteList(node *curr)
{
    while (curr != nullptr)
    {
        node *temp = curr->next;
        delete curr;
        curr = temp;
    }
}

void displayList(node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void removeNthNode(int position, node *curr)
{
    node *temp = curr;

    for (int i = 0; i < position; i++)
    {
        if (temp == nullptr)
        {
            cout << "Invalid position..provide valid position...!!!" << "\n";
            return;
        }
        temp = temp->next;
    }

    node *ptr = curr;
    node *prev;
    while (temp != nullptr)
    {
        prev = ptr;
        ptr = ptr->next;
        temp = temp->next;
    }
    node *tmp = ptr;
    prev->next = ptr->next;
    delete tmp;
}

int main()
{
    node *ptr1 = new node(1);
    ptr1->next = new node(2);
    ptr1->next->next = new node(3);
    ptr1->next->next->next = new node(4);
    ptr1->next->next->next->next = new node(5);
    ptr1->next->next->next->next->next = nullptr;

    node *head = ptr1;

    cout << (findCycle(head) ? "Yes Cycle is present" : "No Cycle present");
    cout << "\n";
    node *result;
    if (result = findStartOfCycle(head))
        cout << "Start of Cycle: " << findStartOfCycle(head)->data << "\n";

    displayList(head);
    // node *temp = reverseList(head);
    // cout << "\n";
    // displayList(temp);

    removeNthNode(2, head);
    displayList(head);

    deleteList(head);
    cout << "\n";
    return 0;
}
