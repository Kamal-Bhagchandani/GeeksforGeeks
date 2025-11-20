class Solution {
  private:
    int maxProfitRec(vector<int> &arr, int ind,
                        int buy, int k,vector<vector<int>> &memo){
        
        int n = arr.size();
        
        if(ind == n)
            return 0;
        
        if(memo[ind][buy] != -1)
            return memo[ind][buy];
        
        int profit;
        
        if(buy == 0)
            profit = max(maxProfitRec(arr, ind + 1, 0, k, memo),
                     maxProfitRec(arr, ind + 1, 1, k, memo) - arr[ind]);
        
        if(buy == 1)
            profit = max(maxProfitRec(arr, ind + 1, 1, k, memo),
                     maxProfitRec(arr, ind + 1, 0, k, memo) - k + arr[ind]);

        return memo[ind][buy] = profit;
    }
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(2,-1));
        
        return maxProfitRec(arr, 0, 0, k, memo);
    }
};