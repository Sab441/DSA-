//Leetcode 240
//Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();//No. of rows
        int m=matrix[0].size();//No. of column
        int row=n-1;
        int col=0;
        while(row>=0 && col<m){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                row--;
            }
            else{
                col++;
            }
        }
        return false;
    }
};
