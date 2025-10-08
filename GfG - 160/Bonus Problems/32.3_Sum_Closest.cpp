/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/3-sum-closest
*/

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int res = 0;
        int minDiff = INT_MAX;
        
        for(int i=0;i<n-2;i++){
            int l=i+1, r=n-1;
            while(l<r){
                int currSum = arr[i]+arr[l]+arr[r];
                if(abs(currSum-target)<minDiff){
                    minDiff = abs(currSum-target);
                    res = currSum;
                }
                else if(abs(currSum-target)==minDiff){
                    res = max(res,currSum);
                }
                if(currSum>target)
                    r--;
                else
                    l++;
            }
        }
        
        return res;
    }
};