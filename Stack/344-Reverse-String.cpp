//Leetcode 344
//Write a function that reverses a string. The input string is given as an array of characters s.

//You must do this by modifying the input array in-place with O(1) extra memory.
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            st.push(s[i]);
        }
        for(int i = 0; i < n; i++){
            s[i]=st.top();
            st.pop();
        }
    }
};
