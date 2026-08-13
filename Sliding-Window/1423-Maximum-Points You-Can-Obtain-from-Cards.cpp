//Leetcode 1423
//There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

//In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

//Your score is the sum of the points of the cards you have taken.

//Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int n=cardPoints.size();
      int lsum=0;
      int rsum=0;
      int maxsum=0;
      for(int i=0;i<k;i++){
            lsum=lsum+cardPoints[i];  
      } 
      maxsum=lsum;
      int ridx=n-1; 
      for(int i=k-1;i>=0;i--){
              lsum=lsum-cardPoints[i];
              rsum=rsum+cardPoints[ridx];
              ridx--;
              maxsum=max(maxsum,lsum+rsum);
      }
      return maxsum;
    }
};
