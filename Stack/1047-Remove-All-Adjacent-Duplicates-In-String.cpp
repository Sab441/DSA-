//Leetcode 1047
//You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

//We repeatedly make duplicate removals on s until we no longer can.

//Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";

        for(int i = 0; i < s.size(); i++) {

            if(res.empty()) {
                res += s[i];
            }
            else if(res.back() == s[i]) {
                res.pop_back();
            }
            else {
                res += s[i];
            }
        }

        return res;
    }
};

  //OR

class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i]){
                st.pop();
                continue;
            }
               st.push(s[i]);
        }
               string res;
               while(!st.empty()){
                res=res+st.top();
                st.pop();
                }
                reverse(res.begin(),res.end());
               return res;
    }
};
