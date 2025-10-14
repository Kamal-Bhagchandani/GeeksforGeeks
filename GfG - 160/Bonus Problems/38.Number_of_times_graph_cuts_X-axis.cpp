/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/number-of-times-graph-cuts-x-axis
*/

// User function Template for C++
class Solution {
  public:
    int touchedXaxis(vector<int>& arr) {
        // code here
        int curr = 0;
        int res = 0;
        
        for(int i=0;i<arr.size();i++){
            int prev = curr;
            curr += arr[i];
            
            if((prev<0 && curr>=0) || (prev>0 && curr<=0)){
                res++;
            }
        }
        
        return res;
    }
};