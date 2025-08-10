/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/minimum-platforms-1587115620
*/

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size(),ans=0;
        int l=0,r=0;
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int count=0;
        while(l<n){
            if(arr[l]<=dep[r]){
                count++;
                l++;
            }
            else{
                count--;
                r++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
