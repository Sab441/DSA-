//Leetcode - 680
//Given a string s, return true if the s can be palindrome after deleting at most one character from it.
class Solution {
public:
    bool pallindromehelper(int i,int j, string s){
        while(i<j){
        if(s[i]!=s[j]){
                 return false;
        }
           i++;
           j--;
        }
           return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            
            if(s[i]!=s[j]){
                 return pallindromehelper(i+1,j,s) || pallindromehelper(i,j-1,s);
            }
               i++;
               j--;
        }
        return true;
        }
};
