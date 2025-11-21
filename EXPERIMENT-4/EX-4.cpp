#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* newNode(int x) {
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    return t;
}

// merge two sorted lists
Node* merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;

    Node *head = NULL, *tail = NULL;

    // pick first node
    if (a->data <= b->data) { head = tail = a; a = a->next; }
    else { head = tail = b; b = b->next; }

    while (a && b) {
        if (a->data <= b->data) {
            tail->next = a; tail = a; a = a->next;
        } else {
            tail->next = b; tail = b; b = b->next;
        }
    }
    if (a) tail->next = a;
    if (b) tail->next = b;
    return head;
}

void printList(Node *p) {
    while (p) { cout << p->data << " "; p = p->next; }
    cout << endl;
}

int main() {
    // first list: 1 -> 3 -> 5
    Node *a = newNode(1);
    a->next = newNode(3);
    a->next->next = newNode(5);

    // second list: 2 -> 4 -> 6
    Node *b = newNode(2);
    b->next = newNode(4);
    b->next->next = newNode(6);

    cout << "List 1: "; printList(a);
    cout << "List 2: "; printList(b);

    Node *c = merge(a, b);

    cout << "Merged: "; printList(c);
    return 0;
}
