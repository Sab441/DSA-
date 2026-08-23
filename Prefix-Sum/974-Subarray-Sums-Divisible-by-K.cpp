//Leetcode 974
//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

//A subarray is a contiguous part of an array.
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        int sum=0;
        unordered_map<int,int>f;
        f[0]=1;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            int rem=sum%k;
            if(rem<0){
                rem=rem+k;
            }
            res=res+f[rem];
            f[rem]++;
        }
        return res;
    }
};
