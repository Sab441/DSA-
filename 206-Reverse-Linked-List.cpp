//Leetcode 206
//Given the head of a singly linked list, reverse the list, and return the reversed list.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

 

