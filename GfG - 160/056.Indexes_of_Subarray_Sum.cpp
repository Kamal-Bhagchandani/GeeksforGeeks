/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/subarray-with-given-sum-1587115621
*/

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        int start=0,end=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>=target){
                end=i;
                while(sum>target and start<end){
                    sum-=arr[start];
                    start++;
                }
                if(sum==target) return {start+1,end+1};
            }
        }
        return {-1};
    }
};