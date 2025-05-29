/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/container-with-most-water0535
*/

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int res=0;
        int l=0,r=n-1;
        while(l<r){
            int minHeight=min(arr[l],arr[r]);
            int width=r-l;
            res=max(res,minHeight*width);
            (arr[l]<arr[r])? l++ : r--;
        }
        return res;
    }
};