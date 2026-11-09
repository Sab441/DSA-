//Leetcode 258
//Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
class Solution {
public:
    int addDigits(int num) {
       if(num<10){
        return num ;
       } 
       int rem=num%10;
       int q=num/10;
       int ans=rem+q;
       return addDigits(ans);

    }
};
