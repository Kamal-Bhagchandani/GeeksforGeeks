/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/subset-sum-problem2014
*/

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        
        if(sum%2!=0) return false;
            
        sum/=2;
        
        int n=arr.size();
        vector<bool> prev(sum+1,false), curr(sum+1);
        
        prev[0]=true;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum ;j++){
                if(j<arr[i-1])
                    curr[j]=prev[j];
                else
                    curr[j]=(prev[j] || prev[j - arr[i-1]]);
            }
            prev=curr;
        }
        
        return prev[sum];
    }
};