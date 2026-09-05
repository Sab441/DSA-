//Leetcode - 1209
//You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

//We repeatedly make k duplicate removals on s until we no longer can.

//Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(st.empty()){
                st.push({c,1});
                continue;
            }
            if(st.top().first != c){
                    st.push({c,1});
                    continue;
            }
            if(st.top().second != (k-1)){
                pair<char,int>p=st.top();
                st.pop();
                st.push({p.first,p.second+1});
                continue;
            }
            st.pop();
        }
        string res="";
        while(!st.empty()){
            pair<char,int>p=st.top();
            st.pop();
            while(p.second){
                res.push_back(p.first);
                p.second--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
