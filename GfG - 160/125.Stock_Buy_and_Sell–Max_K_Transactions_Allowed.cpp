/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/maximum-profit4657
*/

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        if(n==0 || k==0) return 0;
        
        vector<vector<int>> curr(k+1,vector<int>(2,0));
        vector<vector<int>> next(k+1,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--){
            for(int l=1;l<=k;l++){
                
                curr[l][1]=max(-prices[i]+next[l][0],next[l][1]);
                curr[l][0]=max(prices[i]+next[l-1][1],next[l][0]);
                
            }
            next=curr;
        }
        
        return curr[k][1];
    }
};