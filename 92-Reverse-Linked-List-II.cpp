//Leetcode 92
//Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
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

        if(head == NULL) {
            return head;
        }

        if(left == right) {
            return head;
        }

        ListNode* temp = head;
        ListNode* before = NULL;
        int pos = 1;

        while(temp != NULL) {

            if(pos < left) {
                before = temp;
                temp = temp->next;
                pos++;
                continue;
            }

            ListNode* curr = temp;
            ListNode* prev = NULL;

            int times = right - left + 1;

            while(times) {
                ListNode* next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;

                times--;
            }

            temp->next = curr;

            if(before == NULL) {
                return prev;
            }

            before->next = prev;

            return head;
        }

        return head;
    }
};
