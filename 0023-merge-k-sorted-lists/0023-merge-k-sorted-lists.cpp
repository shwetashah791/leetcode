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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](ListNode* a,ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>minHeap(cmp);
        for(ListNode* list:lists){
            if(list){
                minHeap.push(list);
            }
        }
        ListNode dummy(0);
        ListNode* tail=&dummy;

        while(!minHeap.empty()){
            ListNode* smallest=minHeap.top();
            minHeap.pop();
            tail->next=smallest;
            tail=tail->next;

            if(smallest->next){
                minHeap.push(smallest->next);
            }
        }
        return dummy.next;
    }
};