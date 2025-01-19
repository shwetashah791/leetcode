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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head; // No reversal needed for empty list or single node

        // Create a dummy node to simplify edge cases (e.g., reversing from the head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move `prev` to the node before the `left` position
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // Start reversing the sublist
        ListNode* curr = prev->next; // The first node to reverse
        ListNode* next = nullptr;

        for (int i = 0; i < right - left; ++i) {
            next = curr->next;          // Store the next node
            curr->next = next->next;   // Adjust the current node's next pointer
            next->next = prev->next;   // Insert the next node at the start of the reversed sublist
            prev->next = next;         // Update the prev node to point to the new start
        }

        return dummy->next; // Return the updated list, skipping the dummy node
    }
};