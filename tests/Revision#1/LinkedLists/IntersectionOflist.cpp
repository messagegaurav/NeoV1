#include <iostream>
#include <set>

using namespace std;

struct node
{
    int data;
    node *next;
    node(int value) : data(value), next(nullptr) {}
};

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

bool findIntersectionUsingSTL(node *head1, node *head2, node *&result)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return false;
    }
    set<node *> checkMatch;
    while (head1 != nullptr)
    {
        checkMatch.insert(head1);
        head1 = head1->next;
    }
    while (head2 != nullptr)
    {
        auto itr = checkMatch.find(head2);
        if (itr != checkMatch.end())
        {
            result = *itr;
            return true;
        }
        head2 = head2->next;
    }
    return false;
}

node *findIntersection(node *head1, node *head2)
{
    if (!head1 || !head2)
    {
        return nullptr;
    }
    node *a = head1;
    node *b = head2;
    while (a != b)
    {
        a = a ? a->next : head2;
        b = b ? b->next : head1;
    }
    return a;
}

int main()
{
    node *node1 = new node(10);
    node1->next = new node(40);
    node1->next->next = new node(80);
    node1->next->next->next = new node(100);
    node1->next->next->next->next = new node(150);
    node1->next->next->next->next->next = nullptr;

    node *node2 = new node(5);
    node2->next = new node(50);
    node2->next->next = new node(70);
    node2->next->next->next = node1->next->next->next;

    display_list(node1);
    display_list(node2);

    node *intersecPoint = nullptr;
    // if (findIntersectionUsingSTL(node1, node2, intersecPoint))
    // {
    //     cout << "Intesection Point is : " << intersecPoint->data << "\n";
    // }
    // else
    // {
    //     cout << "No intersecting lists..>!!!" << "\n";
    // }
    intersecPoint = findIntersection(node1, node2);
    if (intersecPoint)
    {
        cout << "Intersection Point is: " << intersecPoint->data << "\n";
    }
    else
    {
        cout << "No intersection point !!!" << "\n";
    }
    return 0;
}