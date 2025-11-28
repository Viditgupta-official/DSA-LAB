#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { Node* t = root->right; delete root; return t; }
        else if (!root->right) { Node* t = root->left; delete root; return t; }
        Node* t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder traversal for display
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : elements) root = insert(root, x);

    cout << "Inorder traversal: "; inorder(root); cout << "\n";

    root = deleteNode(root, 20);
    cout << "After deleting 20: "; inorder(root); cout << "\n";

    cout << "Max depth: " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n";
}
