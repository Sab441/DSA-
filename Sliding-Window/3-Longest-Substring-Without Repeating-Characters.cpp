//Leetcode 3
//Given a string s, find the length of the longest substring without duplicate characters.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash + 256, -1);
        int left=0;
        int right=0;
        int n=s.size();
        int maxlen=0;
        while(right<n){
            if(hash[s[right]]!=-1){
                if(hash[s[right]]>=left){
                    left=hash[s[right]]+1;
                }
            }
                int len=right-left+1;
                maxlen=max(len,maxlen);
                hash[s[right]]=right;
                right++;
        }
        return maxlen;
    }
};
