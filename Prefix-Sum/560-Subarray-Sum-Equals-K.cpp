//Leetcode 560
//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

//A subarray is a contiguous non-empty sequence of elements within an array.
//BRUTE FORCE CODE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int n=nums.size();
         int count=0;
         for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    count++;
                }
            }
         }
         return count;
    }
};

//Optimal Solution
class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
         int n=nums.size();
         int PrefixSum[n];
         PrefixSum[0]=nums[0];
         for(int i=1;i<n;i++){
            PrefixSum[i]=PrefixSum[i-1]+nums[i];
         }
         unordered_map<int,int>m;
          m[0]=1;
          int val=0;
         int count=0;
         for(int j=0;j<n;j++){
            val=PrefixSum[j]-K;
            if(m.find(val)!=m.end()){
                count+=m[val];
            }
            if(m.find(PrefixSum[j])==m.end()){
                m[PrefixSum[j]]=0;
            }
            m[PrefixSum[j]]++;
         }
         return count;
    }
};
