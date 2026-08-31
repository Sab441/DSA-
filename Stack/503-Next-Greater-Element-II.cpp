//Leetcode 503
//Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

//The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                int idx = (i + j) % n;

                if(nums[idx] > nums[i]) {
                    res[i] = nums[idx];
                    break;
                }
            }
        }

        return res;
    }
};
