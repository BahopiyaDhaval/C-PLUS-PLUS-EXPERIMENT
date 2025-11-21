#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &s) {
    stack<int> t;
    while(!s.empty()) {
        int x = s.top(); s.pop();
        while(!t.empty() && t.top() > x) { s.push(t.top()); t.pop(); }
        t.push(x);
    }
    while(!t.empty()) { s.push(t.top()); t.pop(); }
}

int main() {
    stack<int> s;
    s.push(34); s.push(3); s.push(31); s.push(98); s.push(92); s.push(23);

    sortStack(s);

    cout << "Sorted Stack: ";
    while(!s.empty()){ cout << s.top() << " "; s.pop(); }
}
