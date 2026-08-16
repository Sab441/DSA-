//Leetcode 152
//Given an integer array nums, find a subarray that has the largest product, and return the product.

//The test cases are generated so that the answer will fit in a 32-bit integer.

//Note that the product of an array with a single element is the value of that element.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxending =nums[0];
        int minending=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=maxending*nums[i];
            int v3=minending*nums[i];
            maxending=max(v1,max(v2,v3));
            minending=min(v1,min(v2,v3));
            ans=max(ans,max(maxending,minending));
        }
        return ans;
    }
};
