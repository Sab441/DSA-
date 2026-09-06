//Leetcode 387
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char,int>f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(f[s[i]]==1)
               return i;
        }
        return -1;
    }
};
