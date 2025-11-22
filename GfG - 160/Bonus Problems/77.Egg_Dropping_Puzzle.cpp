/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dp-bonus-problems/problem/egg-dropping-puzzle-1587115620
*/

class Solution {
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        // code here
        vector<vector<int>> dp(k+1, vector<int>(n+1,0));
        
        int cnt = 0;
        
        while(dp[cnt][n] < k){
            cnt++;
            
            for(int i = 1; i <= n; i++){
                dp[cnt][i] = 1 + dp[cnt - 1][i - 1] + dp[cnt - 1][i];
            }
        }
        
        return cnt;
    }
};