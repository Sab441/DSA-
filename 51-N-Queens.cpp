//Leetcode 51
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Vertical check
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        // Left diagonal check
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        // Right diagonal check
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nQueen(vector<string>& board, int row, int n,
                vector<vector<string>>& ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';

                nQueen(board, row + 1, n, ans);

                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        nQueen(board, 0, n, ans);

        return ans;
    }
};
