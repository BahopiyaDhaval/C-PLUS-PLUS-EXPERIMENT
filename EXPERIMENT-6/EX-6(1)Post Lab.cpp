#include<iostream>
using namespace std;

struct Node{
 int data;
 Node*next;
 Node(int val):data(val),next(nullptr){}
};

class CircularList{
 Node*head;
public:
 CircularList():head(nullptr){}
 
 void insert(int val){
  Node*newNode=new Node(val);
  if(!head){
   head=newNode;
   head->next=head;
  }else{
   Node*temp=head;
   while(temp->next!=head) temp=temp->next;
   temp->next=newNode;
   newNode->next=head;
  }
 }
 
 void makeLoop(int pos){
  if(!head) return;
  Node*last=head;
  while(last->next!=head) last=last->next;
  Node*target=head;
  for(int i=1;i<pos;i++) target=target->next;
  last->next=target;
 }
 
 void show(int n=8){
  if(!head) return;
  Node*temp=head;
  for(int i=0;i<n;i++){
   cout<<temp->data<<" ";
   temp=temp->next;
  }
  cout<<endl;
 }
};

int main(){
 CircularList list;
 list.insert(1);
 list.insert(2);
 list.insert(3);
 list.insert(4);
 list.insert(5);
 
 cout<<"Normal: ";
 list.show(5);
 
 list.makeLoop(2);
 cout<<"With loop: ";
 list.show(10);
 
 return 0;
}