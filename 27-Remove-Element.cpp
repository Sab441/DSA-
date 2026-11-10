//Leetcode 27
//Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

//Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

//Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
//Return k.

class Solution {
public:
    void remove(vector<int>& nums, int n, int i, int val) {
        if(i == n) {
            return;
        }

        if(nums[i] == val) {
            nums.erase(nums.begin() + i);
            remove(nums, n-1, i, val);
        }
        else {
            remove(nums, n, i+1, val);
        }
    }

    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        remove(nums, n, 0, val);

        return nums.size();
    }
};
