#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int value) : data(value), next(nullptr) {}
};

node *createList()
{
    node *node1 = new node(10);
    node1->next = new node(20);
    node1->next->next = new node(30);
    node1->next->next->next = new node(40);
    node1->next->next->next->next = new node(50);
    node1->next->next->next->next->next = node1->next->next;
    return node1;
}

void display_list(node *temp)
{
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void deleteList(node *head)
{
    while (head != nullptr)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}

void detectCycle(node *ptr)
{
    node *fast = ptr, *slow = ptr;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            cout << "found Cycle" << "\n";
            slow = ptr;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            cout << "Cycle starts at : " << slow->data << "\n";

            node *temp = slow;
            while (temp->next != slow)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            cout << "Cycle broken now..!!!" << "\n";
            return;
        }
    }
    cout << "No cycle exists ..!!!" << "\n";
}

int main()
{
    node *root = createList();
    // display_list(root);

    detectCycle(root);

    display_list(root);
    deleteList(root);
    cout << "\n";
    return 0;
}