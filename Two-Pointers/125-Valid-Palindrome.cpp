//Leetcode 125
//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

//Given a string s, return true if it is a palindrome, or false otherwise.
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(!isalnum(s[i])){
                i=i+1;
                continue;
            }
            if(!isalnum(s[j])){
                j=j-1;
                continue;
            }
            if(tolower(s[i])!= tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};
