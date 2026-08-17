//Leetcode 1186
//Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

//Note that the subarray needs to be non-empty after deleting one element.
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        int nodelete=arr[0];
        int onedelete=INT_MIN;
        int ans=arr[0];
        for(int i=1;i<n;i++){
            int prevnodelete=nodelete;
            int prevonedelete=onedelete;
            nodelete=max(nodelete+arr[i],arr[i]);
            int v2;
            if(prevonedelete==INT_MIN)
                    v2=arr[i];
            else
                  v2=prevonedelete+arr[i];
            onedelete=max(v2,prevnodelete);
            ans=max(ans,max(onedelete,nodelete));
        }
        return ans;
    }
};
