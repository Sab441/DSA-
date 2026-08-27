//Leetcode 57
//You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

//Two intervals are considered overlapping if they share at least one point.

//Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

//Return intervals after the insertion.

//Note that you don't need to modify intervals in-place. You can make a new array and return it.
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>>temp;
        bool insert=false;
        for(int i=0;i<n;i++){
            if(insert==false && intervals[i][0]>=newInterval[0]){
                   temp.push_back(newInterval);
                   insert=true;
            }
            temp.push_back(intervals[i]);
        }
        if(insert==false){
            temp.push_back(newInterval);
        }
        vector<vector<int>>res;
        int start1=temp[0][0];
        int end1=temp[0][1];
        for(int i=1;i<temp.size();i++){
            int start2=temp[i][0];
            int end2=temp[i][1];
            if(end1>=start2){
                end1=max(end1,end2);
                continue;
            }
            res.push_back({start1,end1});
            start1=start2;
            end1=end2;
        }
        res.push_back({start1,end1});
        return res;
    }
};
