#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int val) {
        data = val;
        height = -1;
        left = nullptr;
        right = nullptr;
    }
};

void calculateHeights(Node* root) {
    // Base case: if the node is null, return
    if (root == nullptr) {
        return -1;
    }

    // Recursively calculate heights for the left and right subtrees
    int left_height = calculateHeights(root->left, heights);
    int right_height = calculateHeights(root->right, heights);

    root->height = 1 + max(left_height, right_height);
    return root->height;
}

int main() {

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->left->left->left = new Node(70);

    // Calculate the heights of all nodes
    calculateHeights(root, heights);

    return 0;
}
