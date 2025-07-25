/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-ways-to-reach-the-nth-stair-1587115620
*/

class Solution {
  public:
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1,0);
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
};
