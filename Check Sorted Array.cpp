//Geeks for Geeks 
//Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.
class Solution {
  public:
    bool ischeck(int i,int n,vector<int> & arr){
        if(i==n || i==n-1){
            return true;
        }
        if(arr[i]>arr[i+1]){
            return false;
        }
        return ischeck(i+1,n,arr);
    }
    bool isSorted(vector<int>& arr) {
        // code here
        int n=arr.size();
       return ischeck(0,n,arr);
        
    }
};
