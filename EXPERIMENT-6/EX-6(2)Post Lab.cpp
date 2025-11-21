#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* newNode(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = NULL;
    return t;
}
int lengthCircularList(Node* head) {
    if (!head) return 0;
    Node* p = head;
    int count = 1;
    while (p->next != head) { 
        count++;
        p = p->next;
    }
    return count;
}

int main() {

    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head; 

    cout << "Length of circular linked list: " << lengthCircularList(head) << endl;

    return 0;
}
