//Geeks for Geeks Meeting Rooms II
//Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.

//Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n=start.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0;
        int j=0;
        int res=0;
        int room=0;
        while(i<n && j<n){
            if(start[i]<end[j]){
                room++;
                res=max(res,room);
                i++;
            }
            else{
                room--;
                j++;
            }
        }
        return res;
    }
};
