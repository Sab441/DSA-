//Leetcode 15
//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

//Notice that the solution set must not contain duplicate triplets.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1;
        int right=n-1;
        int sum=(-1)*nums[i];
        while(left<right){
            int s=nums[left]+nums[right];
            if(s==sum){
                res.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;
                while(left<n && nums[left]==nums[left-1]){
                    left++;
                }
                while(right>=0 && nums[right]==nums[right+1]){
                    right--;
                }
            }
            else if (s > sum){
                right--;
            }
            else{
                left++;
            }
        }
        }
         return res;
    }
};
