#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int x) : data(x), next(nullptr) {} };

class Stack {
    Node* top; int count;
public:
    Stack() : top(nullptr), count(0) {}
    bool isEmpty() { return !top; }
    void push(int x) { Node* n = new Node(x); n->next = top; top = n; count++; }
    void pop() { if(!isEmpty()){ Node* t=top; top=top->next; delete t; count--; } }
    int peek() { return isEmpty()?-1:top->data; }
    int size() { return count; }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    cout << "Top: " << s.peek() << "\nSize: " << s.size() << endl;
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;
}
