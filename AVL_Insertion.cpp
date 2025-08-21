#include <bits/stdc++.h> 
using namespace std; 
 
struct Node { 
    int key; 
    Node *left; 
    Node *right; 
    int height; 

    Node(int k) { 
        key = k; 
        left = nullptr; 
        right = nullptr; 
        height = 1; 
    }
}; 

int height(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return N->height; 
} 
 
Node *rightRotate(Node *y) { 
    Node *x = y->left; 
    Node *T2 = x->right; 

    x->right = y; 
    y->left = T2; 

    y->height = 1 + max(height(y->left), 
                    height(y->right)); 
    x->height = 1 + max(height(x->left), 
                        height(x->right)); 

    return x; 
} 

Node *leftRotate(Node *x) { 
    Node *y = x->right; 
    Node *T2 = y->left; 

    y->left = x; 
    x->right = T2; 
 
    x->height = 1 + max(height(x->left), 
                        height(x->right)); 
    y->height = 1 + max(height(y->left), 
                        height(y->right)); 
 
    return y; 
} 

// Get balance factor of node N 
int getBalance(Node *N) { 
    if (N == nullptr) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

Node* insert(Node* node, int key) { 
  
    // normal BST insertino
    if (node == nullptr) 
        return new Node(key); 

    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else
        return node; 

    node->height = 1 + max(height(node->left),
                           height(node->right)); 

    // Get the balance factor of this ancestor node 
    int balance = getBalance(node); 

    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 

    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 

    // Left Right Case 
    if (balance > 1 && key > node->left->key) { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 

    // Right Left Case 
    if (balance < -1 && key < node->right->key) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 

    return node; 
} 

void preOrder(Node *root) { 
    if (root != nullptr) { 
        cout << root->key << " "; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

int main() { 
    Node *root = nullptr; 
  
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    
    // Preorder traversal 
    preOrder(root); 
    
    return 0; 
}
