/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/array-bonus-problems/problem/last-moment-before-all-ants-fall-out-of-a-plank
*/

class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        
        for(int i=0;i<left.size();i++){
            ans=max(ans,left[i]);
        }
        for(int i=0;i<right.size();i++){
            ans=max(ans,n-right[i]);
        }
        
        return ans;
    }
};