#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}

// Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> st; string post="";
    for(char c: infix){
        if(isalnum(c)) post+=c;
        else if(c=='(') st.push(c);
        else if(c==')'){ while(st.top()!='('){ post+=st.top(); st.pop(); } st.pop(); }
        else{ while(!st.empty() && precedence(st.top())>=precedence(c)){ post+=st.top(); st.pop(); } st.push(c); }
    }
    while(!st.empty()){ post+=st.top(); st.pop(); }
    return post;
}

// Infix to Prefix
string infixToPrefix(string infix){
    reverse(infix.begin(), infix.end());
    for(char &c: infix){ if(c=='(') c=')'; else if(c==')') c='('; }
    string pre = infixToPostfix(infix);
    reverse(pre.begin(), pre.end());
    return pre;
}

// Prefix to Infix
string prefixToInfix(string pre){
    stack<string> st; reverse(pre.begin(), pre.end());
    for(char c: pre){
        if(isalnum(c)) st.push(string(1,c));
        else{ string a=st.top(); st.pop(); string b=st.top(); st.pop(); st.push("("+a+c+b+")"); }
    }
    return st.top();
}

// Postfix to Infix
string postfixToInfix(string post){
    stack<string> st;
    for(char c: post){
        if(isalnum(c)) st.push(string(1,c));
        else{ string b=st.top(); st.pop(); string a=st.top(); st.pop(); st.push("("+a+c+b+")"); }
    }
    return st.top();
}

int main(){
    string infix="(A-B/C)*(A/K-L)";
    cout<<"Infix: "<<infix<<endl;
    cout<<"Infix -> Postfix: "<<infixToPostfix(infix)<<endl;
    cout<<"Infix -> Prefix: "<<infixToPrefix(infix)<<endl;
    cout<<"Prefix -> Infix: "<<prefixToInfix(infixToPrefix(infix))<<endl;
    cout<<"Postfix -> Infix: "<<postfixToInfix(infixToPostfix(infix))<<endl;
}
