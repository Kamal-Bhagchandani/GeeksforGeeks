/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-palindrome-sub-strings-of-a-string0652
*/

class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n=s.size();
        int res=0;
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                res++;
            }
        }
        for(int gap=2;gap<n;gap++){
            for(int i=0;i<n-gap;i++){
                int j=i+gap;
                if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                    res++;
                }
            }
        }
        return res;
    }
};