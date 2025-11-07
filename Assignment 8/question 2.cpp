#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != nullptr && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right) return findMin(node->right);
    Node* successor = nullptr;
    while (root) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left) return findMax(node->left);
    Node* predecessor = nullptr;
    while (root) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data)
            root = root->left;
        else break;
    }
    return predecessor;
}

int main() {
    Node* root = nullptr;
    int values[] = {20, 8, 22, 4, 12, 10, 14};
    for (int val : values) root = insert(root, val);

    int key = 10;
    Node* foundR = searchRecursive(root, key);
    Node* foundI = searchIterative(root, key);

    cout << "Recursive Search: " << (foundR ? "Found" : "Not Found") << endl;
    cout << "Iterative Search: " << (foundI ? "Found" : "Not Found") << endl;

    cout << "Minimum Element: " << findMin(root)->data << endl;
    cout << "Maximum Element: " << findMax(root)->data << endl;

    Node* node = searchIterative(root, 10);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    cout << "Inorder Successor of " << node->data << ": ";
    if (succ) cout << succ->data << endl; else cout << "None" << endl;

    cout << "Inorder Predecessor of " << node->data << ": ";
    if (pred) cout << pred->data << endl; else cout << "None" << endl;

    return 0;
}
