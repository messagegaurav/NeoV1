#include <iostream>

struct Node
{
    int data;
    Node *next;
    explicit Node(int data) : data(data), next(nullptr) {}
};

Node *createList()
{
    Node *node = new Node(10);
    node->next = new Node(20);
    node->next->next = new Node(30);
    node->next->next->next = new Node(40);
    node->next->next->next->next = nullptr;
    return node;
}

void displayList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " >> ";
        head = head->next;
    }
    std::cout << "\n\n";
}

void deleteList(Node *head)
{
    if (head != nullptr)
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
}

Node *revList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        std::cout << "List is empty ..>!!! \n";
        return head;
    }
    Node *prev = nullptr;
    Node *fwd = nullptr;
    while (head != nullptr)
    {
        fwd = head->next;
        head->next = prev;
        prev = head;
        head = fwd;
    }

    return prev;
}

int main()
{
    auto node = createList();
    displayList(node);
    node = revList(node);
    displayList(node);
    deleteList(node);
    return 0;
}