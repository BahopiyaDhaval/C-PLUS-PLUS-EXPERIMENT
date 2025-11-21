#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* prev;
    Node* next;
    Node(string u) : url(u), prev(nullptr), next(nullptr) {}
};

int main() {
Node* current = new Node("homepage.com");

current->next = new Node("google.com"); current->next->prev = current; current = current->next;
current->next = new Node("youtube.com"); current->next->prev = current; current = current->next;
cout << "Current: " << current->url << endl;

if (current->prev) current = current->prev;
cout << "Back: " << current->url << endl;

if (current->next) current = current->next;
cout << "Forward: " << current->url << endl;

current->next = new Node("twitter.com"); current->next->prev =current; current = current->next;
cout << "Visit new: " << current->url << endl;
return 0;
}
