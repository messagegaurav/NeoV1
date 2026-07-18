#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <pair>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << "data: " << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    cout << "data: " << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << "data: " << root->data << " ";
}

void delete_all(Node *root)
{
    if (!root)
        return;
    delete_all(root->left);
    delete_all(root->right);

    delete root;
    root = nullptr;
    // cout << "data: " << root->data << " ";
}

void BFS_levelOrder(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << "data: " << current->data << " ";
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

void DFS_usingStack(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> staq;
    staq.push(root);
    while (!staq.empty())
    {
        Node *current = staq.top();
        staq.pop();
        cout << "data: " << current->data << " ";
        if (current->right != nullptr)
        {
            staq.push(current->right);
        }
        if (current->left != nullptr)
        {
            staq.push(current->left);
        }
    }
}

int treeHeight(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

int checkBalance(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = checkBalance(root->right);
    if (rightHeight == -1)
        return -1;
    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    else
        return max(leftHeight, rightHeight) + 1;
}

bool balanceorNot(Node *root)
{
    return (checkBalance(root) != -1);
}

int findMaxPath(Node *root, int &maxi)
{
    if (root == nullptr)
        return 0;
    int leftsum = max(0, findMaxPath(root->left, maxi));
    int rightsum = max(0, findMaxPath(root->right, maxi));
    // apex
    maxi = max(maxi, root->data + leftsum + rightsum);
    return root->data + max(leftsum, rightsum);
}

int maxPathSum(Node *root)
{
    int res = INT_MIN;
    findMaxPath(root, res);
    return res;
}

int minDepth(Node *root) // min depth
{
    if (root == nullptr)
        return 0;

    queue<pair<Node *, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
        Node *curr = q.front().first;
        int depth = q.front().second;
        q.pop();
        if ((curr->left == nullptr) && (curr->right == nullptr))
            return depth;
        if (curr->left)
        {
            q.push({curr->left, depth + 1});
        }
        if (curr->right)
        {
            q.push({curr->right, depth + 1});
        }
    }
    return 0;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    BFS_levelOrder(root);
    cout << endl;
    DFS_usingStack(root);
    cout << endl;
    cout << "Tree height: " << treeHeight(root) << endl;
    cout << " Is Tree Balanced: " << (balanceorNot(root) ? "Yes" : "No");
    cout << "\n\nMax Path Sum: " << maxPathSum(root) << endl;
    delete_all(root);
    cout << endl;
    return 0;
}