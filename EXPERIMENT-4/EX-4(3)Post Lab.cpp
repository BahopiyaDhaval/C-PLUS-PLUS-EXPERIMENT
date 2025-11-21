#include<iostream>
using namespace std;

struct ListNode{
 int val;
 ListNode*next;
 ListNode(int x):val(x),next(nullptr){}
};

ListNode*removeDuplicates(ListNode*head){
 ListNode*curr=head;
 while(curr&&curr->next){
  if(curr->val==curr->next->val){
   ListNode*temp=curr->next;
   curr->next=curr->next->next;
   delete temp;
  }else{
   curr=curr->next;
  }
 }
 return head;
}

void printList(ListNode*head){
 while(head){
  cout<<head->val<<" ";
  head=head->next;
 }
 cout<<endl;
}
int main(){
 ListNode*head=new ListNode(1);
 head->next=new ListNode(1);
 head->next->next=new ListNode(2);
 head->next->next->next=new ListNode(3);
 head->next->next->next->next=new ListNode(3);
 head->next->next->next->next->next=new ListNode(4);
 
 cout<<"Original: ";
 printList(head);
 
 head=removeDuplicates(head);
 cout<<"No duplicates: ";
 printList(head);
 
 return 0;
}