//Leetcode 22
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
class Solution {
public:
    void func(int open,int close,int n,string temp,vector<string>&res){
        if(open==n && close==n){
            res.push_back(temp);
            return;
        }
        //open
        if(open<n){
            temp.push_back('(');
            func(open+1,close,n,temp,res);
            temp.pop_back();
        }
        //Close
        if(close<open){
            temp.push_back(')');
            func(open,close+1,n,temp,res);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> res;
        string temp = "";

        func(0, 0, n, temp, res);

        return res;
    }
};
