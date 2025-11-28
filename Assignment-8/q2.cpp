#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* findMax(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (node == nullptr)
        return nullptr;

    // Case 1: Right subtree exists
    if (node->right != nullptr)
        return findMin(node->right);

    // Case 2: No right subtree
    Node* successor = nullptr;
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else
            ancestor = ancestor->right;
    }
    return successor;
}
Node* inorderPredecessor(Node* root, Node* node) {
    if (node == nullptr)
        return nullptr;

    // Case 1: Left subtree exists
    if (node->left != nullptr)
        return findMax(node->left);

    // Case 2: No left subtree
    Node* predecessor = nullptr;
    Node* ancestor = root;
    while (ancestor != node) {
        if (node->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else
            ancestor = ancestor->left;
    }
    return predecessor;
}

// In-order Traversal (for testing)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};

    // Insert elements
    for (int x : elements)
        root = insert(root, x);

    cout << "In-order Traversal of BST: ";
    inorder(root);
    cout << "\n";

    int key = 40;

    // (a) Search
    cout << "\nSearching for " << key << " (Recursive): ";
    Node* res1 = searchRecursive(root, key);
    cout << (res1 ? "Found" : "Not Found");

    cout << "\nSearching for " << key << " (Iterative): ";
    Node* res2 = searchIterative(root, key);
    cout << (res2 ? "Found" : "Not Found");

    // (b) Maximum
    cout << "\n\nMaximum element: " << findMax(root)->data;

    // (c) Minimum
    cout << "\nMinimum element: " << findMin(root)->data;

    // (d) In-order Successor
    Node* succ = inorderSuccessor(root, res1);
    if (succ)
        cout << "\nIn-order Successor of " << key << " is: " << succ->data;
    else
        cout << "\nIn-order Successor of " << key << " does not exist.";

    // (e) In-order Predecessor
    Node* pred = inorderPredecessor(root, res1);
    if (pred)
        cout << "\nIn-order Predecessor of " << key << " is: " << pred->data;
    else
        cout << "\nIn-order Predecessor of " << key << " does not exist.";

    cout << endl;
    return 0;
}
