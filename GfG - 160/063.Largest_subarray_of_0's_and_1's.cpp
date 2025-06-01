/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/largest-subarray-of-0s-and-1s
*/

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        unordered_map<int,int> m;
        int sum=0,res=0;
        
        for(int i=0;i<n;i++){
            (arr[i]==0)? sum-- : sum++;
            
            if(sum==0) res=i+1;
            
            if (m.find(sum)!=m.end()){
                res=max(res,i-m[sum]);
            }
            else {
                m[sum]=i;
            }
        }
        return res;
    }
};