/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-02-05 23:25:40
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-02-06 01:06:34
 */

#include <iostream>
#include <string.h>

using namespace std;

class BST
{
private:
    int data;
    BST *left;
    BST *right;

public:
    BST() : data(0), left(nullptr), right(nullptr) {}
    BST(int);
    BST *insertNode(BST *node, int data);
    void inorder(BST *);
    void deleteNode(BST *root);
    ~BST()
    {
        cout << "\n cleaining up mess...";
    }
};

BST::BST(int _data)
{
    data = _data;
    left = right = nullptr;
}

BST *BST::insertNode(BST *root, int _data)
{
    if (!root)
    {
        cout << "\n only node, became root...";
        return new BST(_data);
    }

    if (_data > root->data)
    {
        cout << "\n its a right node...";
        root->right = insertNode(root->right, _data);
    }
    else
    {
        cout << "\n its a left node...";
        root->left = insertNode(root->left, _data);
    }
    return root;
}

void BST::deleteNode(BST *root)
{
    if (root == nullptr)
    {
        return;
    }
    deleteNode(root->left);
    deleteNode(root->right);
    delete root;
    root = nullptr;
}

void BST::inorder(BST *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << "\n data: " << root->data << endl;
    inorder(root->right);
}

int main()
{
    BST b, *root = nullptr;
    root = b.insertNode(root, 10);
    b.insertNode(root, 50);
    b.insertNode(root, 25);
    b.insertNode(root, 15);
    b.insertNode(root, 35);
    b.insertNode(root, 60);
    b.insertNode(root, 40);
    b.insertNode(root, 70);

    b.inorder(root);

    b.deleteNode(root);

    cout << "\n\n";

    return 0;
}
