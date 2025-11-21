#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int x) {
    Node* t = new Node;
    t->data = x; t->next = NULL;
    return t;
}
void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node *slow = head, *fast = head;

while (fast && fast->next) {
slow = slow->next;
fast = fast->next->next;
if (slow == fast) break;
    }
if (slow != fast) return; 
 slow = head;
Node* prev = NULL;
 while (slow != fast) {
prev = fast;
slow = slow->next;
fast = fast->next;
    }
    prev->next = NULL;
}

void printList(Node* head) {
while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}
int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head->next; 

removeLoop(head);

cout << "Linked list after removing loop: ";
printList(head);

return 0;
}
