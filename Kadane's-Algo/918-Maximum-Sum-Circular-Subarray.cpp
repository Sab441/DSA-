//Leetcode 918
//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

//A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

//A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int maxRes=nums[0];
        //MaxSubarray
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=maxSum+nums[i];
            maxSum=max(v1,v2);
            maxRes=max(maxRes,maxSum);
        }
         //MinSubarray
        int minSum=nums[0];
        int minRes=nums[0];
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=minSum+nums[i];
            minSum=min(v1,v2);
            minRes=min(minRes,minSum);
        }

        //Total array sum
        int Sum=nums[0];
        for(int i=1;i<n;i++){
            Sum+=nums[i];
        }
         
         if(Sum==minRes){
            return maxRes;
         }
         //Circular array
         int Cir=Sum-minRes;
        int  CirRes=max(maxRes,Cir);
        return CirRes;
    }
};
