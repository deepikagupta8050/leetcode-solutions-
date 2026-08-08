class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;

        // Check if k nodes are available
        for (int i = 0; i < k; i++) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // head is now the last node of this group
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};