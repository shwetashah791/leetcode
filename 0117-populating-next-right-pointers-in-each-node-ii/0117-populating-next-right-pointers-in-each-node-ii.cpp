/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node* leftmost=root;
        while(leftmost){
            Node* curr=leftmost;
            leftmost=nullptr;
            Node* prev=nullptr;

            while(curr){
                if(curr->left){
                    if (prev)prev->next=curr->left;
                    else leftmost=curr->left;
                    prev=curr->left;
                }
                if(curr->right){
                    if(prev) prev->next=curr->right;
                    else leftmost=curr->right;
                    prev=curr->right;
                }
                curr=curr->next;
            }
        }
        return root;
    }
};