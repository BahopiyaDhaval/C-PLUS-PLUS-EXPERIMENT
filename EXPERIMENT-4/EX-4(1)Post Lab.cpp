#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* waveSort(ListNode* head) {
    if (!head || !head->next) return head;
    
ListNode *slow = head, *fast = head;
while (fast->next && fast->next->next) {
slow = slow->next;
fast = fast->next->next;
    }

 ListNode* second = slow->next;
slow->next = nullptr;

ListNode *prev = nullptr, *curr = second;
while (curr) {
ListNode* next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
    }
    second = prev;
    
ListNode dummy(0);
ListNode* tail = &dummy;
ListNode* first = head;
    
while (first && second) {
tail->next = first;     
first = first->next;
tail = tail->next;
        
tail->next = second;     
second = second->next;
tail = tail->next;
    }
    
if (first) tail->next = first;
if (second) tail->next = second;
    
return dummy.next;
}

void printList(ListNode* head) {
while (head) {
cout << head->val << " ";
head = head->next;
    }
cout << endl;
}


ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);
    
    cout << "Original: ";
    printList(head1);
    
    head1 = waveSort(head1);
    cout << "Wave sorted: ";
    printList(head1); 
    
    int arr2[] = {1, 2, 3, 4};
    ListNode* head2 = createList(arr2, 4);
    
    cout << "\nOriginal: ";
    printList(head2);
    
    head2 = waveSort(head2);
    cout << "Wave sorted: ";
    printList(head2);  
    
    return 0;
}