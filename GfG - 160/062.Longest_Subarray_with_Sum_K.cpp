/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/longest-sub-array-with-sum-k0809
*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int maxLength=0;
        
        unordered_map<int,int> m;
        
        int prefSum=0;
        
        for(int i=0;i<n;i++){
            prefSum+=arr[i];
            
            if(prefSum==k)
                maxLength=i+1;
                
            else if(m.find(prefSum-k)!=m.end())
                maxLength=max(maxLength,i-m[prefSum-k]);
                
            if(m.find(prefSum)==m.end())
                m[prefSum]=i;
        }
        return maxLength;
    }
};