/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* reverse(ListNode* head){
ListNode* prev = NULL;
ListNode* curr = head;
    while(curr!=NULL){
        ListNode* store = curr->next;
        curr->next = prev;
        prev = curr;
        curr = store;
    }
    return prev;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rev_head = reverse(head);
        ListNode dummy;
        dummy.next = rev_head;
        ListNode* prev = &dummy; 
        ListNode* curr = rev_head;
        for(int i = 1;i<n;i++){
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        
        
        return reverse(dummy.next);
    }
};
