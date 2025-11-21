#include<iostream>
using namespace std;

struct Node{
 int data;
 Node*prev;
 Node*next;
 Node(int val):data(val),prev(nullptr),next(nullptr){}
};

class DoublyLinkedList{
 Node*head;
public:
 DoublyLinkedList():head(nullptr){}
 
 void insert(int val){
  Node*newNode=new Node(val);
  if(!head) head=newNode;
  else{
   newNode->next=head;
   head->prev=newNode;
   head=newNode;
  }
 }
 
 void deleteNode(int val){
  Node*curr=head;
  while(curr){
   if(curr->data==val){
    if(curr->prev) curr->prev->next=curr->next;
    else head=curr->next;
    if(curr->next) curr->next->prev=curr->prev;
    delete curr;
    return;
   }
   curr=curr->next;
  }
 }
 
 bool search(int val){
  Node*curr=head;
  while(curr){
   if(curr->data==val) return true;
   curr=curr->next;
  }
  return false;
 }
 
 void display(){
  Node*curr=head;
  while(curr){
   cout<<curr->data<<" ";
   curr=curr->next;
  }
  cout<<endl;
 }
};

int main(){
 DoublyLinkedList dll;
 dll.insert(30);
 dll.insert(20);
 dll.insert(10);
 
 cout<<"List: ";
 dll.display();
 
 cout<<"Search 20: "<<(dll.search(20)?"Yes":"No")<<endl;
 
 dll.deleteNode(20);
 cout<<"After delete 20: ";
 dll.display();
 
 return 0;
}