//Leetcode 767
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

//Return any possible rearrangement of s or return "" if not possible.
struct cmp{
    bool operator()(pair<int,char>&a,pair<int,char>&b){
        if(a.first!=b.first){
            return a.first<b.first;//Max heap
        }
        return a.second>b.second;//Small character priority
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        string res="";
        int seat=0;
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp> pq;
        unordered_map<char ,int>f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        for (auto i : f) {
            pq.push({i.second, i.first});
        }
        while(!pq.empty()){
            pair<int,char>p=pq.top();
              pq.pop();
            if (res.empty() || res.back() != p.second){
              res.push_back(p.second);
              seat++;
              p.first--;
              if(p.first>0)
              pq.push(p);
            }
            else{
                if (pq.empty()) {
                    return "";
                }
                pair<int,char>p2=pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;
                if(p2.first>0){
                pq.push(p2);
                }
                pq.push(p);
            }
        }
        return res;
    }
};
