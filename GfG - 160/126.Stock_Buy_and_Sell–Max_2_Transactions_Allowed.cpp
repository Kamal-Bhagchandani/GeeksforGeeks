/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/buy-and-sell-a-share-at-most-twice
*/

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        if(n==0) return 0;
        
        vector<vector<int>> curr(3,vector<int>(2,0));
        vector<vector<int>> next(3,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=2;j++){
                curr[j][1]=max(-prices[i]+next[j][0],next[j][1]);
                curr[j][0]=max(prices[i]+next[j-1][1],next[j][0]);
            }
            next=curr;
        }
        return curr[2][1];
    }
};