/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/trapping-rain-water-1587115621
*/

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size(),res=0;
        int l=1,r=n-2;
        int maxL=arr[l-1],maxR=arr[r+1];
        while(l<=r){
            maxL=max(maxL,arr[l]);
            maxR=max(maxR,arr[r]);
            if(maxL<=maxR){
                res+=(0,maxL-arr[l]);
                maxL=max(maxL,arr[l]);
                l++;
            }
            else{
                res+=(0,maxR-arr[r]);
                maxR=max(maxR,arr[r]);
                r--;
            }
        }
        return res;
    }
};