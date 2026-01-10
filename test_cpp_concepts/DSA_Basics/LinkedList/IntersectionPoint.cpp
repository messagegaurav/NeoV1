#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void deleteList(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Node *getIntersectionPoint(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    while (ptr1 != ptr2)
    {
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }
    return ptr1;
}

int main()
{
    // Create first linked list: 1->2->3->4->5
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    Node *intersection = new Node(3);
    head1->next->next = intersection;
    intersection->next = new Node(4);
    intersection->next->next = new Node(5);

    // Create second linked list: 9->8 and then intersecting at node with value 3
    Node *head2 = new Node(9);
    head2->next = new Node(8);
    head2->next->next = intersection; // Intersection at node with value 3

    Node *intersectionNode = getIntersectionPoint(head1, head2);
    if (intersectionNode != nullptr)
        cout << "Intersection at node with value: " << intersectionNode->data << endl;
    else
        cout << "No intersection point." << endl;

    // Cleanup logic to avoid double free and memory leaks
    // Delete nodes in the second list up to the intersection point
    Node *temp = head2;
    while (temp != nullptr && temp != intersection)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }

    deleteList(head1);

    return 0;
}