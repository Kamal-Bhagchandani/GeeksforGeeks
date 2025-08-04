/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/stickler-theif-1587115621
*/

class Solution {
  public:
    int maxLootRec(int n,vector<int> &memo,vector<int> &arr){
        
        if(memo[n]!=-1){
            return memo[n];
        }
        if(n==1){
            memo[n]=arr[n-1];
        }
        else if(n==2){
            memo[n]=max(arr[n-1],arr[n-2]);
        }
        else{
            memo[n]=max(arr[n-1]+maxLootRec(n-2,memo,arr),maxLootRec(n-1,memo,arr));
        }
        return memo[n];
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> memo(n+1,-1);
        
        return maxLootRec(n,memo,arr);
    }
};