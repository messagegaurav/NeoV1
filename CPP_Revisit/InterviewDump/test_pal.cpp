#include <iostream>
#include <string>
using namespace std;
struct Node { char data; Node *next; Node(char v) : data(v), next(nullptr) {} };
bool isPalindrom(Node *root) {
    if (!root) return false;
    if (!root->next) return true;
    Node *prev = nullptr, *fwd = nullptr, *slow = root, *fast = root;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    if (fast) slow = slow->next;
    Node *temp = root;
    while (temp != slow) { fwd = temp->next; temp->next = prev; prev = temp; temp = fwd; }
    while (prev && slow) { if (prev->data != slow->data) return false; prev = prev->next; slow = slow->next; }
    return true;
}
Node* build(string s) { if(s.empty()) return nullptr; Node* r=new Node(s[0]); Node* c=r; for(size_t i=1;i<s.size();i++){c->next=new Node(s[i]);c=c->next;} return r; }
void test(string name, string input, bool expected) {
    bool got = isPalindrom(build(input));
    cout << (got==expected?"PASS":"FAIL") << " | " << name << " | \"" << input << "\" | " << (got?"Yes":"No") << "\n";
}
int main() {
    test("empty",               "",        false);
    test("single char",         "a",       true);
    test("two same",            "aa",      true);
    test("two diff",            "ab",      false);
    test("odd palindrome",      "aba",     true);
    test("odd non-palindrome",  "abc",     false);
    test("even palindrome",     "abba",    true);
    test("even non-palindrome", "abcd",    false);
    test("long palindrome",     "racecar", true);
    test("long non-palindrome", "adde",    false);
    test("all same",            "aaaa",    true);
    test("adda",                "adda",    true);
}
