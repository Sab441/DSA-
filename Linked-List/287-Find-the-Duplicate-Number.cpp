//Leetcode 287
//Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

//There is only one repeated number in nums, return this repeated number.

//You must solve the problem without modifying the array nums and using only constant extra space.
class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow=0;
        int fast=0;
        while(true){
            slow=arr[slow];
            fast=arr[fast];
            fast=arr[fast];
            if(slow==fast){
                slow=0;
                while(slow!=fast){
                slow=arr[slow];
                fast=arr[fast];
                }
                return slow;
            }
        }
        return -1;
    }
};
 
