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


class LinkedList {
public:
   Node* head;


   LinkedList() {
       head = NULL;
   }


   void insert(int value) {
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


   void countOddEven() {
       int oddCount = 0, evenCount = 0;


       Node* temp = head;


       while (temp != NULL) {
           if (temp->data % 2 == 0)
               evenCount++;
           else
               oddCount++;


           temp = temp->next;
       }


       cout << "Total EVEN elements: " << evenCount << endl;
       cout << "Total ODD elements : " << oddCount << endl;
   }
};


int main() {
   cout<<"Bahopiya Dhaval\n92400133132\n";
   LinkedList list;


    list.insert(10);
   list.insert(21);
   list.insert(32);
   list.insert(43);
   list.insert(54);


   list.countOddEven();


   return 0;
}
