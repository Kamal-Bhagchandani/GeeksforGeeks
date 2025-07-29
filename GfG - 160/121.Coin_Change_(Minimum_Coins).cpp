/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/number-of-coins1824
*/

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<int> dp(sum+1,INT_MAX);
        dp[0]=0;
        
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=sum;j++){
                if(dp[j-coins[i]] != INT_MAX){
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);
                }
            }
        }
        
        return ((dp[sum]!=INT_MAX)? dp[sum] : -1);
    }
};