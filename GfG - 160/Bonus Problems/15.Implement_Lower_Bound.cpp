/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-bonus-problems/problem/implement-lower-bound
*/

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        
        int low=0,high=n-1;
        int res=n;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]>=target){
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return res;
        // Using builtin function: (return only following line)
        // return lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    }
};
