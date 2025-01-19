/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* curr=head;
        while(curr){
            Node* copy=new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }
    
    curr=head;
    while(curr){
        if(curr->random){
            curr->next->random=curr->random->next;
        }
        curr=curr->next->next;
    }
    Node* dummyHead=new Node(0);
    Node* copyCurr=dummyHead;
    curr=head;
    while(curr){
        copyCurr->next=curr->next;
        curr->next=curr->next->next;

        curr=curr->next;
        copyCurr=copyCurr->next;
    }
    return dummyHead->next;
    }
};