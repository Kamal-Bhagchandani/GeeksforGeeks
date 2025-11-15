/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dp-bonus-problems/problem/distinct-occurrences
*/

class Solution {
  private:
    int countSubsequences(int i, int j, string &pat, string &txt, vector<vector<int>> &dp){
        if(i == 0)
            return 1;
        if(j == 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = countSubsequences(i, j-1, pat, txt, dp);
        
        if(pat[i-1] == txt[j-1]){
            res += countSubsequences(i-1, j-1, pat, txt, dp);
        }
        
        dp[i][j] = res;
        
        return dp[i][j];
    }
  public:
    int subseqCount(string &txt, string &pat) {
        // code here
        int m = pat.length(), n = txt.length();
        
        if(m > n) return 0;
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,-1));
        
        return countSubsequences(m, n, pat, txt, dp);
    }
};