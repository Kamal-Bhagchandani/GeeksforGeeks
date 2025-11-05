/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-bonus-problems/problem/attend-all-meetings-ii
*/

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        
        int room = 0;
        int res = 0;
        
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int i = 0, j = 0;
        
        while(i<start.size()){
            if(start[i]<end[j]){
                room++;
                i++;
            }
            else{
                room--;
                j++;
            }
            res = max(res,room);
        }
        
        return res;
    }
};
