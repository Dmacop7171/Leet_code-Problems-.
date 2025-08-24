// AVL Tree = self-balancing Binary Search Tree (BST).
// Balance is maintained using rotations after every insertion.

// 📌 AVL Tree Property

// For every node:

// Balance Factor (BF)
// =
// Height(left subtree)
// −
// Height(right subtree)
// Balance Factor (BF)=Height(left subtree)−Height(right subtree)

// If BF = -1, 0, +1 → Tree is balanced ✅

// If BF < -1 or > +1 → Tree is unbalanced ❌ → Rotation required

// 📌 Types of Rotations

// LL Rotation (Right Rotation) → Unbalanced at left child’s left

// RR Rotation (Left Rotation) → Unbalanced at right child’s right

// LR Rotation (Left-Right) → Unbalanced at left child’s right

// RL Rotation (Right-Left) → Unbalanced at right child’s left

// 📌 Algorithm for Insertion

// Insert node as in a normal BST

// Update height of current node

// Calculate Balance Factor

// If unbalanced, perform rotation depending on case

// 📌 C++ Implementation of AVL Insertion
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
    Node(int val) {
        key = val;
        left = right = NULL;
        height = 1; // leaf node has height 1
    }
};

// Utility: height of node
int getHeight(Node* root) {
    if (!root) return 0;
    return root->height;
}

// Utility: balance factor
int getBalance(Node* root) {
    if (!root) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

// Right rotation (LL case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // new root
}

// Left rotation (RR case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // new root
}

// Insert function
Node* insert(Node* root, int key) {
    // Step 1: Normal BST insert
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // duplicates not allowed

    // Step 2: Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Step 3: Get balance factor
    int balance = getBalance(root);

    // Step 4: Check 4 cases
    // LL Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // unchanged root
}

// Preorder traversal
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Insert values
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Preorder should be balanced
    cout << "Preorder traversal of AVL tree:\n";
    preOrder(root);

    return 0;
}

📌 Example Walkthrough

Insert order: 10, 20, 30

Insert 10 → Balanced

Insert 20 → Still balanced

Insert 30 → Unbalanced at root (10) with BF = -2 (RR case) → Left Rotation

Balanced tree: 20 as root, 10 left, 30 right
