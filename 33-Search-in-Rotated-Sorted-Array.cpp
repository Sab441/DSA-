//Leetcode 33
//There is an integer array nums sorted in ascending order (with distinct values).

//Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

//Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

//You must write an algorithm with O(log n) runtime complexity.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int res=0;
        while(low<=high){
            int guess=(low+high)/2;
            if(nums[guess]>nums[n-1]){
                low=guess+1;
            }
            else{
                res=guess;
                high=guess-1; 
            }
        }
        //Divide in two parts
        //Part 1
        int low1=0;
        int high1=res-1;
        int low2=res;
        int high2=n-1;
        while(low1<=high1){
            int mid=(low1+high1)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high1=mid-1;
            }
            else{
                low1=mid+1;
            }
        }
        //Part 2
        while(low2<=high2){
            int mid=(low2+high2)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high2=mid-1;
            }
            else{
                low2=mid+1;
            }
        }
        return -1;
    }
};
