//Leetcode 74
//You are given an m x n integer matrix matrix with the following two properties:

//Each row is sorted in non-decreasing order.
//The first integer of each row is greater than the last integer of the previous row.
//Given an integer target, return true if target is in matrix or false otherwise.

//You must write a solution in O(log(m * n)) time complexity.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();//no. of rows
        int m=matrix[0].size();//no. of columns
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int guess=(low+high)/2;
            int row=guess/m;
            int column=guess%m;
            if(matrix[row][column]==target){
                return true;
            }
            else if(matrix[row][column]>target){
                 high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return false;
    }
};
