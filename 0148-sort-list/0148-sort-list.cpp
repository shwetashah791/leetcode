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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid=getMid(head);
        ListNode* rightHalf=mid->next;
        mid->next=nullptr;

        ListNode* left=sortList(head);
        ListNode* right=sortList(rightHalf);
        return merge(left,right);
    }
    private:
    ListNode* getMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* curr=&dummy;
        while(l1 && l2){
            if(l1->val <l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
    curr->next=l1?l1:l2;
    return dummy.next;
    }
};