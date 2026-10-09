//Leetcode 347
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
struct cmp{
    bool operator() (pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first!=b.first){
            return a.first>b.first;//agr true hua to b min hoga agr false hua to a minimum hoga
           
        }
         return a.second>b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int>res;
       priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
       unordered_map<int,int>f;
       for(int i=0;i<n;i++){
        f[nums[i]]++;
       }
       for(auto i:f){
        int element=i.first;
        int freq=i.second;
        pair<int,int> curr={freq,element};
        if(pq.size()<k){
            pq.push(curr);
            continue;
        }
        if(curr.first>pq.top().first){
            pq.pop();
            pq.push(curr);
        }
         }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
       return res;
    }
};
