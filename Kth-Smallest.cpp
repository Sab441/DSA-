//Geeks for Geeks
//Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;//max heap
        int n=arr.size();
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<n;i++){
            if(arr[i]>=pq.top()){
                continue;
            }
            else{
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};
