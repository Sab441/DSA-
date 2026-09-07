//Leetcode 383
//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

//Each letter in magazine can only be used once in ransomNote.
class Solution {
public:
    bool fun(unordered_map<char,int>&need,unordered_map<char,int>&have){
              for(auto i:need){
                char c=i.first;
                int fneed=i.second;
                int fhave=have[c];
                if(fhave<fneed)
                return false;
              }
              return true;
    }
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        unordered_map<char,int>need;
        unordered_map<char,int>have;
        for(int i=0;i<n;i++){
            need[ransomNote[i]]++;
        }
        for(int i=0;i<m;i++){
            have[magazine[i]]++;
        }
        return fun(need,have);
    }
};
