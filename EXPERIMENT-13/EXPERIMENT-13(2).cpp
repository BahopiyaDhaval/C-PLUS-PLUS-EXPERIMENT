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

// Pre-Order Traversal: Root, Left, Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// In-Order Traversal: Left, Root, Right
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Post-Order Traversal: Left, Right, Root
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Creating a sample tree
    //        10
    //       /  \
    //     20    30
    //    / \     \
    //   40 50    60

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->right = new Node(60);

    cout << "Pre-Order Traversal: ";
    preorder(root);
    cout << endl;

    cout << "In-Order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

