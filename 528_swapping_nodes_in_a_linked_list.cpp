class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* first = head;

        // kth node from beginning
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        ListNode* second = head;
        ListNode* temp = first;

        // Move temp to the end
        while (temp->next != NULL) {
            temp = temp->next;
            second = second->next;
        }

        swap(first->val, second->val);

        return head;
    }
};