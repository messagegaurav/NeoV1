#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

Node *remDuplicateFromList(Node *root)
{
    if (root == nullptr) return nullptr;

    Node dummy(0);
    dummy.next = root;

    Node *head = root;
    Node *prev = &dummy;
    bool isDup = false;
    while ((head != nullptr) && (head->next != nullptr))
    {
        while (head->next != nullptr && head->data == head->next->data)
        {
            Node *temp = head->next;
            head->next = temp->next;
            delete temp;
            isDup = true;
        }
        if (isDup)
        {
            prev->next = head->next;
            delete head;
            head = prev->next;
            isDup = false;
        }
        else
        {
            prev = head;
            head = head->next;
        }
    }
    return dummy.next;
}

Node* build(vector<int> vals) {
    if (vals.empty()) return nullptr;
    Node* root = new Node(vals[0]);
    Node* cur = root;
    for (size_t i = 1; i < vals.size(); i++) { cur->next = new Node(vals[i]); cur = cur->next; }
    return root;
}

string collect(Node* root) {
    string res;
    while (root) { res += to_string(root->data) + (root->next ? "->" : ""); root = root->next; }
    return res.empty() ? "empty" : res;
}

void freeList(Node* root) { while(root) { Node* t = root->next; delete root; root = t; } }

void test(string name, vector<int> input, string expected) {
    Node* root = build(input);
    Node* result = remDuplicateFromList(root);
    string got = collect(result);
    cout << (got == expected ? "PASS" : "FAIL") << " | " << name << " | got: " << got << " | expected: " << expected << "\n";
    freeList(result);
}

int main() {
    test("empty list",          {},              "empty");
    test("no duplicates",       {1,2,3},         "1->2->3");
    test("all same",            {2,2,2},         "empty");
    test("dups in middle",      {1,2,2,3},       "1->3");
    test("dups at start",       {1,1,2,3},       "2->3");
    test("dups at end",         {1,2,3,3},       "1->2");
    test("multiple dup groups", {1,1,2,2,3},     "3");
    test("single element",      {1},             "1");
    test("two same elements",   {1,1},           "empty");
    test("two diff elements",   {1,2},           "1->2");
    test("original test case",  {1,2,2,2,3},     "1->3");
}
