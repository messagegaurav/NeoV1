#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *next;
    Node(char value) : data(value), next(nullptr) {}
};

bool isPalindrom(Node *root)
{
    if (root == nullptr) return false;
    if (root->next == nullptr) return true;

    Node *prev = nullptr, *fwd = nullptr;
    Node *slow = root, *fast = root;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = root;
    while (temp != slow)
    {
        fwd = temp->next;
        temp->next = prev;
        prev = temp;
        temp = fwd;
    }
    while (prev != nullptr && slow != nullptr)
    {
        if (prev->data != slow->data)
            return false;
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}

Node* build(string s) {
    if (s.empty()) return nullptr;
    Node* root = new Node(s[0]);
    Node* cur = root;
    for (size_t i = 1; i < s.size(); i++) { cur->next = new Node(s[i]); cur = cur->next; }
    return root;
}

void freeList(Node* root) { while(root) { Node* t = root->next; delete root; root = t; } }

void test(string name, string input, bool expected) {
    Node* root = build(input);
    bool got = isPalindrom(root);
    cout << (got == expected ? "PASS" : "FAIL") << " | " << name << " | input: \"" << input << "\" | expected: " << (expected ? "Yes" : "No") << " | got: " << (got ? "Yes" : "No") << "\n";
    // cant use freeList directly since list is modified, just leak in test
}

int main() {
    test("empty",               "",       false);
    test("single char",         "a",      true);
    test("two same",            "aa",     true);
    test("two diff",            "ab",     false);
    test("odd palindrome",      "aba",    true);
    test("odd non-palindrome",  "abc",    false);
    test("even palindrome",     "abba",   true);
    test("even non-palindrome", "abcd",   false);
    test("long palindrome",     "racecar",true);
    test("long non-palindrome", "adde",   false);
    test("all same chars",      "aaaa",   true);
}
