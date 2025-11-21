#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[100]; 
    int capacity;
public:
Stack(int size) { top = -1; capacity = size; }
bool isEmpty() { return top == -1; }
bool isFull() { return top == capacity - 1; }

void push(int x) {
if (isFull()) { cout << "Stack Overflow\n"; return; }
arr[++top] = x;
    }

void pop() {
if (isEmpty()) { cout << "Stack Underflow\n"; return; }
top--;
    }

int peek() {
if (isEmpty()) { cout << "Stack is empty\n"; return -1; }
return arr[top];
    }

int size() { return top + 1; }
};

int main() {
Stack s(5); 
s.push(10);
s.push(20);
s.push(30);

cout << "Top element: " << s.peek() << endl;
cout << "Stack size: " << s.size() << endl;
s.pop();
cout << "Top after pop: " << s.peek() << endl;

 if (s.isEmpty()) cout << "Stack is empty\n";
 else cout << "Stack is not empty\n";

return 0;
}
