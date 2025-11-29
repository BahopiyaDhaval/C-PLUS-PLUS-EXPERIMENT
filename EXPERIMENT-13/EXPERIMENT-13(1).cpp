#include <iostream>
#include <queue>
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

// Insert node using LinkedList-based Binary Tree representation
Node* insertNode(Node* root, int value) {
    Node* newNode = new Node(value);

    // If tree is empty
    if (root == nullptr) 
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Try inserting at left
        if (temp->left == nullptr) {
            temp->left = newNode;
            return root;
        } else {
            q.push(temp->left);
        }

        // Try inserting at right
        if (temp->right == nullptr) {
            temp->right = newNode;
            return root;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

// Inorder Traversal (to verify insertion)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);

    cout << "Inorder traversal after insertions: ";
    inorder(root);
}



