#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = nullptr;
    }
};

void printInorder(struct Node* node)
{
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(struct Node* node)
{
    if (node == nullptr)
        return;
    printInorder(node->left);
    printInorder(node->right);
    cout << node->data << " ";
}

void printPreorder(struct Node* node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    printInorder(node->left);
    printInorder(node->right);
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Inorder: " << "\n";
    printInorder(root);

    cout << "Preorder: " << "\n";
    printPreorder(root);

    cout << "Postorder: " << "\n";
    printPostorder(root);

    return 0;
}
