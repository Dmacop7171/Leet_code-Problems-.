#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to calculate height of each node
int calculateHeight(Node* root, unordered_map<Node*, int> &heightMap) {
    if (root == NULL) return 0;

    int leftHeight = calculateHeight(root->left, heightMap);
    int rightHeight = calculateHeight(root->right, heightMap);

    int currHeight = 1 + max(leftHeight, rightHeight);
    heightMap[root] = currHeight;  // store height of current node

    return currHeight;
}

int main() {
    // Constructing a sample Binary Tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    unordered_map<Node*, int> heightMap;

    calculateHeight(root, heightMap);

    // Printing height of each node
    cout << "Height of each node:\n";
    cout << "Node " << root->data << " -> " << heightMap[root] << "\n";
    cout << "Node " << root->left->data << " -> " << heightMap[root->left] << "\n";
    cout << "Node " << root->right->data << " -> " << heightMap[root->right] << "\n";
    cout << "Node " << root->left->left->data << " -> " << heightMap[root->left->left] << "\n";
    cout << "Node " << root->left->right->data << " -> " << heightMap[root->left->right] << "\n";

    return 0;
}
