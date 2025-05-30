/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/equilibrium-point-1587115620
*/

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
        int totalSum=0;
        int leftSum=0;
        
        for(int i=0;i<n;i++)
            totalSum+=arr[i];
            
        for(int i=0;i<n;i++){
            totalSum-=arr[i];   //for right sum
            if(leftSum==totalSum) return i;
            leftSum+=arr[i];
        }
        return -1;
    }
};