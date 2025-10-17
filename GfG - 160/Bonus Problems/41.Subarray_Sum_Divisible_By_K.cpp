/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/sub-array-sum-divisible-by-k2617
*/

class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& arr, int k) {
        // Your code goes here
        int n = arr.size();
        int res = 0;
        int sum = 0;
        
        unordered_map<int,int> prefCnt;
        
        for (int i=0;i<n;i++){
            sum = ((sum + arr[i])%k+k)%k;
            res += prefCnt[sum];
            if(sum==0)
                res++;
            prefCnt[sum]++;
        }
        
        return res;
    }
};
