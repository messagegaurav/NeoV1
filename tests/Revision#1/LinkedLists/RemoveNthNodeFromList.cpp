#include <iostream>

struct Node
{
    int data;
    Node *next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

Node *createList()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = nullptr;
    return head;
}

void displayList(Node *node)
{
    while (node != nullptr)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << "\n";
}

void deleteList(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Node *removeNthNodeFromEnd(Node *head, int pos)
{
    if (head == nullptr || pos <= 0)
        return head;

    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < pos; ++i)
    {
        if (fast == nullptr)
        {
            std::cout << "invalid position provided: " << pos << "\n";
            return head;
        }
        fast = fast->next;
    }

    if (fast == nullptr)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *nodeToDelete = slow->next;
    slow->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}

int main()
{
    Node *root = createList();
    displayList(root);
    root = removeNthNodeFromEnd(root, 1);
    displayList(root);
    deleteList(root);
    return 0;
}