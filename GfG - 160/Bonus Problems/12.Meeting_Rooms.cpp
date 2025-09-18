/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-bonus-problems/problem/attend-all-meetings
*/

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end());
        
        for(auto i=0;i<arr.size()-1;i++){
            if(arr[i][1]>arr[i+1][0])
                return false;
        }
        
        return true;
    }
};