//Geeks For Geeks
//Given a positive number n. Find the sum of all the digits of n.
class Solution {
  public:
    int sumOfDigits(int n) {
        // code here
        if(n==0){
            return 0;
        }
        int rem=n%10;
        int q=n/10;
        return rem+sumOfDigits(q);
    }
};
