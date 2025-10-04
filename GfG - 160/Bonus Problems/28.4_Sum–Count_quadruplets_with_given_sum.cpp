/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/count-quadruplets-with-given-sum
*/

class Solution {
  public:
    int countSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int count=0;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int temp=arr[i]+arr[j];
                count+=mp[target-temp];
            }
            for(int j=0;j<i;j++){
                int temp=arr[i]+arr[j];
                mp[temp]++;
            }
        }
        
        return count;
    }
};