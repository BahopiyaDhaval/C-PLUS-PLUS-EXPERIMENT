#include <iostream>
using namespace std;

class Deque {
    int arr[100];
    int front, rear, cap;

public:
    Deque(int c = 10) {
        cap = c;
        front = -1;
        rear = -1;
    }

    bool isEmpty()  { return front == -1; }
    bool isFull()   { return (front == 0 && rear == cap-1) || (front == rear+1); }

    // Insert at front
    void insertFront(int x) {
        if (isFull()) { cout << "Deque Overflow\n"; return; }
        if (isEmpty()) front = rear = 0;
        else if (front == 0) front = cap - 1;
        else front--;
        arr[front] = x;
    }

    // Insert at rear
    void insertRear(int x) {
        if (isFull()) { cout << "Deque Overflow\n"; return; }
        if (isEmpty()) front = rear = 0;
        else if (rear == cap - 1) rear = 0;
        else rear++;
        arr[rear] = x;
    }

    // Delete from front
    void deleteFront() {
        if (isEmpty()) { cout << "Deque Underflow\n"; return; }
        if (front == rear) front = rear = -1;
        else if (front == cap - 1) front = 0;
        else front++;
    }

    // Delete from rear
    void deleteRear() {
        if (isEmpty()) { cout << "Deque Underflow\n"; return; }
        if (front == rear) front = rear = -1;
        else if (rear == 0) rear = cap - 1;
        else rear--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    cout << "Front: " << dq.getFront() << ", Rear: " << dq.getRear() << "\n";

    dq.deleteFront();
    cout << "After deleteFront, Front: " << dq.getFront() << "\n";

    dq.deleteRear();
    cout << "After deleteRear, Rear: " << dq.getRear() << "\n";

    return 0;
}
