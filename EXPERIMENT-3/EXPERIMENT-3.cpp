#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insert(int x) {
    Node* n = new Node{x, NULL};
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

// Delete first occurrence
void removeNode(int x) {
    if (!head) return;
    if (head->data == x) { Node* t = head; head = head->next; delete t; return; }

    Node* t = head;
    while (t->next && t->next->data != x) t = t->next;
    if (t->next) {
        Node* del = t->next;
        t->next = del->next;
        delete del;
    }
}

// Search
bool search(int x) {
    Node* t = head;
    while (t) {
        if (t->data == x) return true;
        t = t->next;
    }
    return false;
}

// Traverse
void traverse() {
    Node* t = head;
    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    traverse();                      // 10 20 30
    cout << search(20) << endl;      // 1
    removeNode(20);
    traverse();                      // 10 30
}
