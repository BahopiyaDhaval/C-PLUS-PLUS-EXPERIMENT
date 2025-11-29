#include <iostream>
#include <climits>   // <<--- needed for INT_MIN
using namespace std;

/* ---------------------------
   1) Linear Queue (Array)
   --------------------------- */
class LinearQueue {
    int *arr;
    int capacity;
    int frontIdx;
    int rearIdx;
public:
    LinearQueue(int cap=10) {
        capacity = cap;
        arr = new int[capacity];
        frontIdx = 0;
        rearIdx = -1;
    }
    ~LinearQueue(){ delete[] arr; }

    bool isEmpty() const { return rearIdx < frontIdx; }
    bool isFull()  const { return rearIdx >= capacity - 1; }
    int size()     const { return isEmpty() ? 0 : (rearIdx - frontIdx + 1); }

    bool enqueue(int x) {
        if (isFull()) return false;
        arr[++rearIdx] = x;
        return true;
    }

    int dequeue() {
        if (isEmpty()) return INT_MIN;
        return arr[frontIdx++];
    }

    int front() const {
        if (isEmpty()) return INT_MIN;
        return arr[frontIdx];
    }
};/* ---------------------------
   2) Circular Queue (Array)
   --------------------------- */
class CircularQueue {
    int *arr;
    int capacity;
    int frontIdx;
    int count;
public:
    CircularQueue(int cap=10) {
        capacity = cap;
        arr = new int[capacity];
        frontIdx = 0;
        count = 0;
    }
    ~CircularQueue(){ delete[] arr; }

    bool isEmpty() const { return count == 0; }
    bool isFull()  const { return count == capacity; }
    int size()     const { return count; }

    bool enqueue(int x) {
        if (isFull()) return false;
        int rear = (frontIdx + count) % capacity;
        arr[rear] = x;
        ++count;
        return true;
    }

    int dequeue() {
        if (isEmpty()) return INT_MIN;
        int val = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        --count;
        return val;
    }

    int front() const {
        if (isEmpty()) return INT_MIN;
        return arr[frontIdx];
    }
};

/* ----------------------------------------
   3) Circular Queue (Linked List implementation)
   - Use tail pointer so enqueue/dequeue are O(1)
   ---------------------------------------- */
class CircularQueueLinked {
    struct Node {
        int val;
        Node* next;
        Node(int v): val(v), next(nullptr) {}
    };
    Node* tail; // tail->next is head (front)
    int cnt;
public:
    CircularQueueLinked(): tail(nullptr), cnt(0) {}
    ~CircularQueueLinked() {
        if (!tail) return;
        // break circle then delete
        Node* head = tail->next;
        tail->next = nullptr;
        Node* cur = head;
        while (cur) { Node* nx = cur->next; delete cur; cur = nx; }
    }

    bool isEmpty() const { return tail == nullptr; }
    int size() const { return cnt; }

    void enqueue(int x) {
        Node* node = new Node(x);
        if (!tail) {
            node->next = node;
            tail = node;
        } else {
            node->next = tail->next; // new->head
            tail->next = node;
            tail = node;
        }
        ++cnt;
    }

    int dequeue() {
        if (!tail) return INT_MIN;
        Node* head = tail->next;
        int val = head->val;
        if (head == tail) { // single node
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
        --cnt;
        return val;
    }

    int front() const {
        if (!tail) return INT_MIN;
        return tail->next->val;
    }
};

/* ---------------------------
   Demo main()
   --------------------------- */
int main(){
    cout << "=== Linear Queue (array) demo ===\n";
    LinearQueue lq(5);
    cout << "enqueue 1..5 -> ";
    for(int i=1;i<=5;i++) cout << (lq.enqueue(i) ? "ok " : "full ");
    cout << "\nTry enqueue 6 -> " << (lq.enqueue(6) ? "ok" : "full") << "\n";
    cout << "Front: " << lq.front() << ", Size: " << lq.size() << "\n";
    cout << "Dequeue all: ";
    while(!lq.isEmpty()) cout << lq.dequeue() << " ";
    cout << "\n\n";

    cout << "=== Circular Queue (array) demo ===\n";
    CircularQueue cq(4);
    cq.enqueue(10); cq.enqueue(20); cq.enqueue(30);
    cout << "front: " << cq.front() << ", size: " << cq.size() << "\n";
    cout << "dequeue -> " << cq.dequeue() << "\n";
    cq.enqueue(40); cq.enqueue(50); // wraparound enqueue
    cout << "Elements dequeued in order: ";
    while(!cq.isEmpty()) cout << cq.dequeue() << " ";
    cout << "\n\n";

    cout << "=== Circular Queue (linked list) demo ===\n";
    CircularQueueLinked clq;
    clq.enqueue(101); clq.enqueue(102); clq.enqueue(103);
    cout << "front: " << clq.front() << ", size: " << clq.size() << "\n";
    cout << "dequeue -> " << clq.dequeue() << "\n";
    clq.enqueue(104); clq.enqueue(105);
    cout << "Remaining: ";
    while(!clq.isEmpty()) cout << clq.dequeue() << " ";
    cout << "\n";

    return 0;
}

