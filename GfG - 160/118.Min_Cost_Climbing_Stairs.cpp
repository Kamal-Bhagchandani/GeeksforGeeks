/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/min-cost-climbing-stairs
*/

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n=cost.size();
        
        if(n==1)
            return cost[0];
            
        vector<int> dp(n);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<n;i++)
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        
        return min(dp[n-1],dp[n-2]);
    }
};