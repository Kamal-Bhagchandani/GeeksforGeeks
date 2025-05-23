/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-with-given-sum-in-a-sorted-array4940
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n=arr.size();
        int res=0;
        int l=0,r=n-1;
        while(l<r){
            int sum=arr[l]+arr[r];
            if(sum>target) r--;
            else if(sum<target) l++;
            else{
                int cnt1=0;
                int cnt2=0;
                int ele1=arr[l];
                int ele2=arr[r];
                while(l<=r && ele1==arr[l]){
                    cnt1++;
                    l++;
                }
                while(l<=r && ele2==arr[r]){
                    cnt2++;
                    r--;
                }
                if(ele1==ele2)
                res += cnt1*(cnt1-1)/2;
                
                else res += cnt1*cnt2; 
            }
        }
        return res;
    }
};