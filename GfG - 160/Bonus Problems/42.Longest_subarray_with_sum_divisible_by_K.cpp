/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/longest-subarray-with-sum-divisible-by-k1259
*/

// User function template for C++
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // Complete the function
        int n = arr.size();
        int res = 0;
        
        unordered_map<int,int> prefIdx;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum = ((sum+arr[i]) % k + k) % k;
            
            if(sum == 0)
                res = i+1;
            else if(prefIdx.find(sum)!=prefIdx.end())
                res = max(res,i-prefIdx[sum]);
            else
                prefIdx[sum] = i; 
        }
        
        return res;
    }
};