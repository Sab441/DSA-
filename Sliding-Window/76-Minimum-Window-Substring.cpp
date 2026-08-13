//Leetcode 76
//Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

//The testcases will be generated such that the answer is unique.
class Solution {
public:
    bool check(vector<int> &have, vector<int> &needed){
        for(int i=0;i<256;i++){
            if(have[i]<needed[i]){
                return false;
            }
        
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> have(256,0);
        vector<int> needed(256,0);
        int n=s.size();
        int low=0;
        int high=0;
        int start=0;
        int res=INT_MAX;
        for(char ch : t){
        needed[ch]++;
       }
        for(high=0;high<n;high++){
            have[s[high]]++;
            while(check(have,needed)){
                int len=high-low+1;
                if(res>len){
                    res=len;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }
        }
        if(res == INT_MAX){
          return "";
          }
          else{
        return s.substr(start,res);
          }
    }
};
