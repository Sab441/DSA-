//Leetcode - 424
//You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

//Return the length of the longest substring containing the same letter you can get after performing the above operations.
class Solution {
public:
int find(vector<int>& f) { 
    int maxint = 0;
     for(int i = 0; i < 26; i++) {
         maxint = max(maxint, f[i]);
          } 
          return maxint;
           }
    int characterReplacement(string s, int k) {
        int n=s.size();
        int high=0;
        int low=0;
        int len=0;
        int maxcount=0;
        int diff=0;
        int result=0;
         vector<int> f(26, 0);
        for(high=0;high<n;high++)
        {
            f[s[high] - 'A']++;
            int len=high-low+1;
            int maxint=find(f);
            int diff=len-maxint;
            while(diff>k){
                f[s[low] - 'A']--;
                low++;
                maxint=find(f);
                len=high-low+1;
                diff=len-maxint;
            }
            len=high-low+1;
            result=max(result,len);
        }
        return result;
    }
};
