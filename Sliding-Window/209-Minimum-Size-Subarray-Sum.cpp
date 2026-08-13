//Leetcode 209
//Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=0;
        int result=INT_MAX;
        int sum=0;
        while(high<n){
            sum=sum+nums[high];
            while(sum>=target){
                int len=high-low+1;
               result=min(result,len);
                sum=sum-nums[low];
                low++;
            }
            high++;
        }
        return (result==INT_MAX)?0:result;
    }
};
