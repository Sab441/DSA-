//Leetcode 23
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

//Merge all the linked-lists into one sorted linked-list and return it.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
        decltype([](ListNode* a, ListNode* b) {
            return a->val > b->val;
        })> pq;

        for (auto node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        tail->next = NULL;
        return dummy->next;
    }
};
