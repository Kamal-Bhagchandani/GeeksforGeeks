/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/matrix-chain-multiplication0303
*/

class Solution {
  public:
    int recFunc(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
        if(i+1==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res=INT_MAX;
        
        for(int k=i+1;k<j;k++){
            int curr = recFunc(i,k,arr,dp)+recFunc(k,j,arr,dp)+
                       arr[i]*arr[k]*arr[j];
            
            res=min(res,curr);
        }
        dp[i][j]=res;
        
        return res;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        dp[0][n-1]=recFunc(0,n-1,arr,dp);
        
        return dp[0][n-1];
    }
};