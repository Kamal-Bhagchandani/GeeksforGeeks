/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/coin-change2448
*/

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n=coins.size();
        vector<int> dp(sum+1);
        
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=sum;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[sum];
    }
};