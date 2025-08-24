// Got it 👍 Let’s go step by step with AVL Tree Deletion.
// Deletion in an AVL tree is similar to normal BST deletion, but after deleting the node we must rebalance the tree (using rotations).

// 🔑 Steps of AVL Deletion:

// Perform normal BST deletion:

// If node is a leaf → just delete.

// If node has one child → replace with child.

// If node has two children → replace with inorder successor (or predecessor) and delete that.

// Update height of the current node.

// Check balance factor = height(left) - height(right):

// If > 1 or < -1, the tree is unbalanced.

// Apply one of the four rotations:

// Left-Left (LL) → Right Rotate

// Right-Right (RR) → Left Rotate

// Left-Right (LR) → Left Rotate on child + Right Rotate

// Right-Left (RL) → Right Rotate on child + Left Rotate

// ✅ C++ Code for AVL Deletion
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

// Utility: height of node
int height(Node* root) {
    return root ? root->height : 0;
}

// Utility: balance factor
int getBalance(Node* root) {
    return root ? height(root->left) - height(root->right) : 0;
}

// Right Rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // new root
}

// Left Rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;

    // update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // new root
}

// Get inorder successor (smallest in right subtree)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left) current = current->left;
    return current;
}

// Delete node in AVL
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    // 1. Normal BST deletion
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) { // no child
                temp = root;
                root = NULL;
            } else // one child
                *root = *temp;
            free(temp);
        } else {
            // Node with 2 children
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If tree had only one node
    if (!root) return root;

    // 2. Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Get balance factor
    int balance = getBalance(root);

    // 4. Rebalance cases
    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Utility: inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = new Node(9);
    root->left = new Node(1);
    root->right = new Node(10);
    root->right->right = new Node(11);
    root->right->right->right = new Node(12);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 10);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}


// 👉 This handles all cases (0, 1, or 2 children) and rebalances after deletion.
