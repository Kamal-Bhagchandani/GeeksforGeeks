/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/triplet-sum-in-array-1587115621
*/

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-2;i++){
            int l = i+1, r = n-1;
            int requiredSum=target - arr[i];
            
            while(l<r){
                if(arr[l]+arr[r]==requiredSum)
                    return true;
                else if(arr[l]+arr[r]<requiredSum)
                    l++;
                else
                    r--;
            }
        }
        
        return false;
    }
};