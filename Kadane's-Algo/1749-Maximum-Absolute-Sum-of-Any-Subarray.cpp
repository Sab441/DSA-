//Leetcode 1749
//You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

//Return the maximum absolute sum of any (possibly empty) subarray of nums.

//Note that abs(x) is defined as follows:

//If x is a negative integer, then abs(x) = -x.
//If x is a non-negative integer, then abs(x) = x.
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxEnding=nums[0];
        int minEnding=nums[0];
        int ans=abs(nums[0]);
        for(int i=1;i<n;i++){
            int prevmax=maxEnding;
            int prevmin=minEnding;
            int v1=nums[i];
            int v2=nums[i]+prevmax;
            maxEnding=max(v1,v2);
            int v4=nums[i]+prevmin;
            minEnding=min(v1,v4);
            ans=max(ans,max(abs(minEnding),abs(maxEnding)));
        }
        return ans;
    }
};
