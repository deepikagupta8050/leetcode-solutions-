class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* left = list1;

        for (int i = 0; i < a - 1; i++) {
            left = left->next;
        }

        ListNode* right = left->next;

        for (int i = a; i <= b; i++) {
            right = right->next;
        }

        left->next = list2;

        while (list2->next != NULL) {
            list2 = list2->next;
        }

        list2->next = right;

        return list1;
    }
};