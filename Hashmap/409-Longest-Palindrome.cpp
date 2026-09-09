//Leetcode 409
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

//Letters are case sensitive, for example, "Aa" is not considered a palindrome.
class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        bool odd=false;
        unordered_map<char,int>f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        int res=0;
        for(auto i:f){
              int val=i.second;
              if(i.second%2==0)
               res+=val;
              else
                odd=true;
        }
        if(odd==false)
        return res;
        else{
            for(auto i:f){
                int val=i.second;
                if(val % 2==1){
                    res=res+(val-1);
                }
            }
        }
        return res+1;
    }
};
