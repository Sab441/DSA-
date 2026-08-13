//Leetcode 977
//Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size=nums.size();
        vector<int> neg;
        vector<int> pos;
        for(int i=0;i<size;i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        if(neg.size()==0){ //No negative element
            for(int i=0;i<size;i++){
                nums[i]=nums[i]*nums[i];
            }
            return nums;
        }
        else if(pos.size()==0){ //No positive element
            for(int i=0;i<size;i++){
                nums[i]=nums[i]*nums[i];
            }
                reverse(nums.begin(),nums.end());
            
            return nums;
        }
        else{
        int i=0; //starting of pos array
        int j=0; //Starting of negative array
        int n=neg.size(); //size of negative
        int m=pos.size(); //size of positive
        vector<int> res; //resultant vector
        reverse(neg.begin(),neg.end());
        while(i<m && j<n){
            if(pos[i]*pos[i]<neg[j]*neg[j]){
                res.push_back(pos[i]*pos[i]);
                i++;
            }
            else{
                res.push_back(neg[j]*neg[j]);
                j++;
            }
        }
        while(j<n){
            res.push_back(neg[j]*neg[j]);
            j++;
        }
        while(i<m){
            res.push_back(pos[i]*pos[i]);
            i++;
        }
        // for(int i=0;i<n;i++){
        //     nums[i]=res[i];
        // }
        return res;
        }
    }
};
