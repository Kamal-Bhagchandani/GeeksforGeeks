/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-pairs-whose-sum-is-less-than-target
*/

// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int n=arr.size(),res=0;
        sort(arr.begin(),arr.end());
        int l=0;
        int r=n-1;
        while(l<r){
            if(arr[l]+arr[r]<target){
                res+=r-l;
                l++;
            }
            else r--;
            
        }
        return res;
    }
};
