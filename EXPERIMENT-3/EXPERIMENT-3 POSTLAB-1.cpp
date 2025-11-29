#include <iostream>
using namespace std;


class Node {
public:
   int data;
   Node* next;
};




int countNodes(Node* head) {
   int count = 0;       
   Node* temp = head;      




  
   while (temp != NULL) {
       count++;         
       temp = temp->next;  
   }




   return count;
}




int main() {
 
   Node* head = new Node();
   Node* second = new Node();
   Node* third = new Node();




   head->data = 10;
   head->next = second;




   second->data = 20;
   second->next = third;




   third->data = 30;
   third->next = NULL;




   int total = countNodes(head);
   cout << "Total number of nodes in LinkedList = " << total << endl;




   return 0;
}
