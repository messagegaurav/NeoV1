#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to validate BST
bool isBSTUtil(Node *root, long long minVal, long long maxVal)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    /*
        Example BST:
                6
               / \
              2   8
             / \ / \
            0  4 7  9
              / \
             3   5
    */
    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << (isBST(root) ? "Tree is a valid BST" : "Tree is NOT a BST") << "\n";

    return 0;
}
