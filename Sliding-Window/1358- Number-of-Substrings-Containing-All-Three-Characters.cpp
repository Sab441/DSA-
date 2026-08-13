//Leetcode 1358
//Given a string s consisting only of characters a, b and c.

//Return the number of substrings containing at least one occurrence of all these characters a, b and c.
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> mp(3,0);
        int left=0;
        int right=0;
        int result=0;
        while(right<n){
            char ch=s[right];
            mp[ch-'a']++;
            while(mp[0]>0 && mp[1]>0 && mp[2]>0){
                result=result+(n-right);
                mp[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return result;
    }
};
