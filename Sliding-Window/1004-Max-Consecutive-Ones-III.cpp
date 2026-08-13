//Leetcode 1004
//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=0;
        int maxlen=0;
        int zeros=0;
        while(right<n){
            if(nums[right]==0){
                zeros++;
            }
            if(zeros>k){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
            if(zeros<=k){
                int len=right-left+1;
                maxlen=max(len,maxlen);

            }
            right++;
        }
        return maxlen;
    }
};
