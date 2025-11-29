#include <iostream>
using namespace std;


class Node {
public:
   int data;
   Node* next;
   Node(int value) {
       data = value;
       next = NULL;
   }
};


void insertAtEnd(Node* &head, int value) {
   Node* newNode = new Node(value);


   if (head == NULL) { 
       head = newNode;
       return;
   }


   Node* temp = head;
   while (temp->next != NULL) {
       temp = temp->next;
   }
   temp->next = newNode;
}


void printList(Node* head) {
   Node* temp = head;
   while (temp != NULL) {
       cout << temp->data << " -> ";
       temp = temp->next;
   }
   cout << "NULL\n";
}


void splitOddEven(Node* head, Node* &oddList, Node* &evenList) {
   Node* temp = head;


   while (temp != NULL) {
       if (temp->data % 2 == 0) {
        
           insertAtEnd(evenList, temp->data);
       } else {
         
           insertAtEnd(oddList, temp->data);
       }
       temp = temp->next;
   }
}


int main() {
   cout<<"Bahopiya Dhaval\n92400133132\n";
   Node* head = NULL;
   Node* oddList = NULL;
   Node* evenList = NULL;




   insertAtEnd(head, 10);
   insertAtEnd(head, 21);
   insertAtEnd(head, 32);
   insertAtEnd(head, 45);
   insertAtEnd(head, 50);


   cout << "Original Linked List:\n";
   printList(head);




   splitOddEven(head, oddList, evenList);


   cout << "\nOdd Elements Linked List:\n";
   printList(oddList);


   cout << "\nEven Elements Linked List:\n";
   printList(evenList);


   return 0;
}


