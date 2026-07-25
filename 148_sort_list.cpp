class Solution {
public:

    ListNode* findMid(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* a, ListNode* b) {

        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (a != NULL && b != NULL) {

            if (a->val <= b->val) {
                cur->next = a;
                a = a->next;
            } else {
                cur->next = b;
                b = b->next;
            }

            cur = cur->next;
        }

        if (a != NULL) {
            cur->next = a;
        } else {
            cur->next = b;
        }

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = findMid(head);

        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        right = sortList(right);

        return merge(left, right);
    }
};