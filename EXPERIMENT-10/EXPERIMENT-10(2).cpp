#include <iostream>
#include <climits>   // <-- needed for INT_MIN
using namespace std;

struct Node {
    int data, priority;
    Node* next;
    Node(int d, int p): data(d), priority(p), next(nullptr) {}
};

class PriorityQueueLL {
    Node* head;
public:
    PriorityQueueLL(): head(nullptr) {}

    bool isEmpty() { return head == nullptr; }

    void enqueue(int value, int pr) {
        Node* n = new Node(value, pr);

        if (!head || pr > head->priority) {
            n->next = head;
            head = n;
            return;
        }

        Node* cur = head;
        while (cur->next && cur->next->priority >= pr)
            cur = cur->next;

        n->next = cur->next;
        cur->next = n;
    }

    int dequeue() {
        if (isEmpty()) return INT_MIN;
        Node* temp = head;
        int val = head->data;
        head = head->next;
        delete temp;
        return val;
    }

    int peek() {
        if (isEmpty()) return INT_MIN;
        return head->data;
    }

    void display() {
        Node* cur = head;
        cout << "Queue: ";
        while (cur) {
            cout << "[" << cur->data << ":" << cur->priority << "] ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueueLL pq;
    pq.enqueue(10, 2);
    pq.enqueue(5, 5);
    pq.enqueue(20, 3);
    pq.enqueue(7, 5);

    pq.display();

    cout << "Dequeue: " << pq.dequeue() << endl;
    pq.display();

    return 0;
}
