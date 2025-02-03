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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode dummy(0);
        dummy.next=head;
        ListNode *prevGroupEnd=&dummy,*curr=head;
        while(true){
            ListNode *groupStart=curr;
            ListNode *temp=curr;
            int count=0;
            //Check if there are at least k nodes left to reverse
            while(temp && count<k){
                temp=temp->next;
                count++;
            }
            if(count<k) break;

            //reverse k nodes
            ListNode * prev=nullptr,*next=nullptr;
            for(int i=0;i<k;i++){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            prevGroupEnd->next=prev;
            groupStart->next=curr;
            prevGroupEnd=groupStart;
        }
     return dummy.next;
    }
};