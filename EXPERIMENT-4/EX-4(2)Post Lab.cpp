#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


int kthSmallest(ListNode* head, int k) {
    ListNode* curr = head;
    
for (int i = 1; i < k && curr != nullptr; i++) {
        curr = curr->next;
    }
return (curr != nullptr) ? curr->val : -1;
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
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
ListNode* head = createList(arr, n);
    
cout << "1st smallest: " << kthSmallest(head, 1) << endl;  
cout << "3rd smallest: " << kthSmallest(head, 3) << endl;  
cout << "6th smallest: " << kthSmallest(head, 6) << endl;  
cout << "7th smallest: " << kthSmallest(head, 7) << endl;  
    return 0;
}
