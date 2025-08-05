/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/house-robber-ii
*/

class Solution {
  public:
    int maxValTab(int x,int y, vector<int> &arr){
        int n=arr.size();
        int prev2=arr[x];
        int prev1=max(arr[x],arr[x+1]);
        for(int j=x+2;j<=y;j++){
            int take = arr[j]+prev2;
            int noTake=prev1;
            int curr = max(take,noTake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        if(n==0) return 0;
        if(n==1) return arr[0];
        int ans=max(ans,maxValTab(0,n-2,arr));
        ans=max(ans,maxValTab(1,n-1,arr));
        return ans;
    }
};
