/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/subset-sum-problem-1611555638
*/

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<bool> prev(sum+1,false),curr(sum+1);
        prev[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j<arr[i-1])
                    curr[j]=prev[j];
                else
                    curr[j]=(prev[j] || prev[j-arr[i-1]]);
                    
            }
            prev=curr;
        }
        return prev[sum];
    }
};