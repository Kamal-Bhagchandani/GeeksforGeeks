/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/square-root
*/

class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l=0,r=n;
        int res=0;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            int midSquared=mid*mid;
            
            if(midSquared==n){
                return mid;
            }
            
            else if(midSquared<n){
                l=mid+1;
                res=mid;
            }
            else r=mid-1;
        }
        
        return res;
    }
};