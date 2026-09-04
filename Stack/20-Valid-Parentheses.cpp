//Leetcode 20
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//An input string is valid if:

//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            //Opening bracket 
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            } //end if
            //Closing bracket
            else{
            if(st.empty()){
                return false;
            } //end if
            if(
                (st.top()=='(' && s[i]==')') ||
                (st.top()=='[' && s[i]==']')   ||
                (st.top()=='{' && s[i]=='}')
            )
                st.pop();
            else{
                return false;
            }//end else
            } //end else
        } //end for
        if(!st.empty()){
            return false;
        }//end if
        return true;
    }
};
