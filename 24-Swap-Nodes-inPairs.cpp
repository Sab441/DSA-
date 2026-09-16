//Leetcode 24
//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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
    void reverse(ListNode* left,int size){
        ListNode* curr=left;
        ListNode* prev=NULL;
        while(size--){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        int size=2;
        ListNode* left=head;
        ListNode* res=NULL;
        ListNode* right;
        ListNode* prevleft=NULL;
        while(true){
            right=left;
            for(int i=0;i<(size-1);i++){
                if(right==NULL){
                    break;
                }
                right=right->next;
            }
            if(right){
                ListNode* nextleft=right->next;
                reverse(left,size);
                left->next = nextleft;
                if(prevleft){
                    prevleft->next=right;
                }
                    else{
                    res=right;
                }

                    prevleft=left;
                    left=nextleft;
            }
                else{
                    //Khatam hai sb
                    if(prevleft){
                        prevleft->next=left;
                    }
                    else{//Agr ek hi node hai to
                        res=left;
                    }
                    break;
            }
        }
        return res;
    }
};
