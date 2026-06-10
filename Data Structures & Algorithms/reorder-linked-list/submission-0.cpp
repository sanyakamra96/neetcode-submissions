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

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL and fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = NULL;
        // reverse second half
        ListNode* prev=NULL;
        ListNode* curr=second;

        while(curr!=NULL){
            ListNode* store = curr->next;
            curr->next = prev;
            prev = curr;
            curr = store;
        }

        second = prev;


        while(second!=NULL and first!=NULL){
        ListNode* store1 = first->next;
        first->next = second;
        first = store1;
        
        ListNode* store2 = second->next;
        second->next = first;
        second = store2;
        }
        


    }
};
