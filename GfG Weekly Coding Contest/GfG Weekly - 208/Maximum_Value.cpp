/*
Question Link: https://practice.geeksforgeeks.org/contest/gfg-weekly-208-rated-contest/problems
*/

class Solution {
  public:
    int maximumValue(vector<int>& arr) {
        // code here
        int minVal=*min_element(arr.begin(),arr.end());
        int maxVal=*max_element(arr.begin(),arr.end());
        
        // As (abs(arr[i]-arr[j])+abs(arr[j]-arr[k])+abs(arr[k]-arr[i]))
        // = 2*max(arr[i],arr[j],arr[k])-min(arr[i]+arr[j]+arr[k])
        return 2*(maxVal-minVal);
    }
};