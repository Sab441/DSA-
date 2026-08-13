//Leetcode 9
//Given an integer x, return true if x is a palindrome, and false otherwise.
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long n=x;
        long long revNum=0;
        while(n>0){
            int r=n%10;
            revNum=(revNum*10) +r;
            n=n/10;
        }
        if(revNum==x){
            return true;
        }
        else{
            return false;
        }
    }
};
