/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-increasing-subsequence-1587115620
*/

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> lis(n,1);
        
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(arr[i]>arr[prev] && lis[i]<lis[prev]+1)
                    lis[i]=lis[prev]+1; 
            }
        }
        return *max_element(lis.begin(),lis.end());
    }
};