class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* head = nullptr;
        ListNode* store = nullptr;

        // decide first node
        if(temp1->val <= temp2->val){
            head = temp1;
            temp1 = temp1->next;
        }
        else{
            head = temp2;
            temp2 = temp2->next;
        }

        store = head;

        while(temp1 != nullptr && temp2 != nullptr){

            if(temp1->val <= temp2->val){
                store->next = temp1;
                temp1 = temp1->next;
            }
            else{
                store->next = temp2;
                temp2 = temp2->next;
            }

            store = store->next;
        }

        if(temp1 != nullptr)
            store->next = temp1;

        if(temp2 != nullptr)
            store->next = temp2;

        return head;
    }
};