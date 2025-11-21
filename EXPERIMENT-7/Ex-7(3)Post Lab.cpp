#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s = "HelloWorld";
    stack<char> st;
    for(char c : s) st.push(c);
    cout << "Reversed: ";
    while(!st.empty()) { cout << st.top(); st.pop(); }
    cout << endl;
}
