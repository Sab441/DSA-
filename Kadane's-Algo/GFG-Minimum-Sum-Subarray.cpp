//Geeks for Geeks Minimum Sum Subarray
//Given an array arr[], find the sub-array containing at least one number which has the minimum sum and return its sum.
class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int bestending=arr[0];
        int ans=arr[0];
        for(int i=1;i<n;i++){
            int v1=arr[i];
            int v2=arr[i]+bestending;
            bestending=min(v1,v2);
            ans=min(ans,bestending);
        }
        return ans;
    }
};
