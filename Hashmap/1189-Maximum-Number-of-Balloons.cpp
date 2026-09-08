//Leetcode 1189
//Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

//You can use each character in text at most once. Return the maximum number of instances that can be formed.
class Solution {
public:
    int fun(unordered_map<char,int>&have,unordered_map<char,int>&need){
         int res=INT_MAX;
        for(auto i:need){
            char c=i.first;
            int fneed=i.second;
            int fhave=have[c];
            int times=fhave/fneed;
            res=min(res,times);
        }
        return res;
    }
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<char,int>have;
        for(int i=0;i<n;i++){
            have[text[i]]++;
        }
        unordered_map<char,int>need;
        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;
        return fun(have,need);
    }
};
