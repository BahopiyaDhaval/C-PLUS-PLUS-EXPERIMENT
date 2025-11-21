#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main() {
    string sentence = "I love icecream";
    stack<string> st;
    string word;
    istringstream iss(sentence);
    while(iss >> word) st.push(word);

    cout << "Reversed words: ";
    while(!st.empty()){ cout << st.top() << " "; st.pop(); }
    cout << endl;
}
