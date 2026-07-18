#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int value) : data(value), next(nullptr) {}
};

node *createList1()
{
    node *node1 = new node(10);
    node1->next = new node(40);
    node1->next->next = new node(80);
    node1->next->next->next = new node(100);
    node1->next->next->next->next = new node(150);
    node1->next->next->next->next->next = nullptr;
    return node1;
}

node *createList2()
{
    node *node1 = new node(5);
    node1->next = new node(50);
    node1->next->next = new node(70);
    node1->next->next->next = new node(90);
    node1->next->next->next->next = new node(140);
    node1->next->next->next->next->next = nullptr;
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

node *mergeSortedList(node *ptr1, node *ptr2)
{
    node *head, *tail;
    if (ptr1->data < ptr2->data)
    {
        head = ptr1;
        ptr1 = ptr1->next;
    }
    else
    {
        head = ptr2;
        ptr2 = ptr2->next;
    }
    tail = head;
    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1->data < ptr2->data)
        {
            tail->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            tail->next = ptr2;
            ptr2 = ptr2->next;
        }
        tail = tail->next;
    }
    if (ptr1 != nullptr)
    {
        tail->next = ptr1;
    }
    else
    {
        tail->next = ptr2;
    }
    return head;
}

int main()
{
    node *root1 = createList1();
    node *root2 = createList2();

    display_list(root1);
    display_list(root2);
    node *finalList = mergeSortedList(root1, root2);
    display_list(finalList);
    deleteList(finalList);
    return 0;
}