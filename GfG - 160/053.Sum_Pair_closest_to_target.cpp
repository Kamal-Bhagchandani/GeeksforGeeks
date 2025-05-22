/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-in-array-whose-sum-is-closest-to-x1124
*/

// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int minDiff=INT_MAX;
        
        vector<int> res;
        
        int l=0,r=n-1;
        while(l<r){
            int sum=arr[l]+arr[r];
            int absDiff=abs(sum-target);
            if(absDiff<minDiff){
                minDiff=absDiff;
                res={arr[l],arr[r]};
            }
            if(sum<target) l++;
            else if(sum>target) r--;
            else return res;
        }
        return res;
    }
};