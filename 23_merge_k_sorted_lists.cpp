class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (ListNode* node : lists) {
            if (node != NULL)
                pq.push(node);
        }

        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            cur->next = node;
            cur = cur->next;

            if (node->next != NULL)
                pq.push(node->next);
        }

        return head->next;
    }
};