//Leetcode 16
//Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

//Return the sum of the three integers.

//You may assume that each input would have exactly one solution.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int res_sum=nums[0]+nums[1]+nums[2];
    int Max_diff=abs(res_sum-target);
    for(int i=0;i<n-2;i++){
        int left=i+1;
        int right=n-1;
        while(left<right){
        int sum=nums[left]+nums[right]+nums[i];
        int diff=abs(sum-target);
        if(diff<Max_diff){
            Max_diff=diff;
            res_sum=sum; 
        }
        
        if(sum==target){
           return target;
        }
        else if(sum > target){
            right--;
        }
        else{
            left ++;
        }
        }
        

    }
    return res_sum;
    }
};
