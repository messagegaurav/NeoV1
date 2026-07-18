#include <iostream>
#include <string>
using namespace std;
struct Node
{
    char data;
    Node *next;
    Node(char v) : data(v), next(nullptr) {}
};

bool isPalindrom(Node *root)
{
    if (!root)
        return false;
    if (!root->next)
        return true;
    Node *prev = nullptr, *fwd = nullptr, *slow = root, *fast = root;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "slow at: " << slow->data << " fast: " << (fast ? fast->data : '?') << "\n";
    if (fast)
        slow = slow->next; // skip middle for odd
    cout << "second half starts at: " << slow->data << "\n";
    Node *secondHalf = slow;
    Node *temp = root;
    // reverse first half up to secondHalf
    while (temp != secondHalf)
    {
        fwd = temp->next;
        temp->next = prev;
        prev = temp;
        temp = fwd;
    }
    cout << "reversed first half, prev at: " << prev->data << "\n";
    while (prev && slow)
    {
        cout << "comparing: " << prev->data << " vs " << slow->data << "\n";
        if (prev->data != slow->data)
            return false;
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}
Node *build(string s)
{
    if (s.empty())
        return nullptr;
    Node *r = new Node(s[0]);
    Node *c = r;
    for (size_t i = 1; i < s.size(); i++)
    {
        c->next = new Node(s[i]);
        c = c->next;
    }
    return r;
}
int main()
{
    cout << "--- aba ---\n";
    cout << (isPalindrom(build("aba")) ? "Yes" : "No") << "\n";
    cout << "--- racecar ---\n";
    cout << (isPalindrom(build("racecar")) ? "Yes" : "No") << "\n";
}
