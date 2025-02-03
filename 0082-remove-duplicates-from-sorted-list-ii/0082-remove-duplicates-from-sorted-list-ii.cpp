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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;

        while(head){
            bool isDuplicate=false;
            while(head->next && head->val==head->next->val){
                head=head->next;
                isDuplicate=true;
            }
            if(isDuplicate){
                prev->next=head->next;
            }else{
                prev=prev->next;
            }
            head=head->next;
        }
        return dummy.next;
    }
};