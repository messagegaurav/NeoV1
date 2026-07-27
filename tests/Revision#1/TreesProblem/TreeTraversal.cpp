#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

void level_order(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *root = que.front();
        que.pop();
        cout << root->data << " ";
        if (root->left)
            que.push(root->left);
        if (root->right)
            que.push(root->right);
    }
}

// LCA in general tree
Node *LCA(Node *root, Node *p, Node *q)
{
    if (!root || root == p || root == q)
        return root;

    Node *left = LCA(root->left, p, q);
    Node *right = LCA(root->right, p, q);

    if (left && right)
        return root;
    return left ? left : right;
}

// LCA in BST
Node *LCA_BST(Node *root, Node *p, Node *q)
{
    while (root)
    {
        if (p->data < root->data && q->data < root->data)
            root = root->left;
        else if (p->data > root->data && q->data > root->data)
            root = root->right;
        else
        {
            return root;
        }
    }
}

int heightOfTree(Node *root)
{
    if (!root)
        return 0;
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    Node *node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->right->right = new Node(6);

    cout << "Inorder Traversal: " << "\n";
    inorder(node);

    cout << "\n"
         << "Pre Order traversal: " << "\n";
    preorder(node);

    cout << "\n"
         << "Post Order traversal: " << "\n";
    postorder(node);

    cout << "\n"
         << "Level Order traversal: " << "\n";
    level_order(node);

    cout << "\n"
         << "LCA root: " << LCA(node, node->left, node->left->right)->data << "\n";

    cout << "Height of tree: " << heightOfTree(node) << "\n";

    cout << "\n";
    return 0;
}
