/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/find-repetitive-element-from-1-to-n-1
*/

// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int ans=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            ans^=i;
        }
        for(int val : arr){
            ans^=val;
        }
        return ans;
    }
};