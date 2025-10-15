/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-bonus-problem/problem/longest-subarray-with-majority-greater-than-k
*/

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mp;
        int ans=0, sum=0;
        
        for(int i=0;i<arr.size();i++) {
            if(arr[i]<=k) sum--;
            else sum++;
            
            if(sum>0) ans=i+1;
            else{
                if(mp.count(sum-1)){
                    ans=max(ans,i-mp[sum-1]);
                }
            }
            if(!mp.count(sum)) mp[sum]=i;
        }
        
        return ans;
    }
};