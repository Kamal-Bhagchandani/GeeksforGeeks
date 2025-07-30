/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/minimum-number-of-jumps-1587115620
*/

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<=i+arr[i] && j<n;j++){
                if(dp[j]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
        }
        return (dp[0]==INT_MAX? -1 : dp[0]);
    }
};
