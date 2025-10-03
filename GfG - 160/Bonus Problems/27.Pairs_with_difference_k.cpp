/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/pairs-with-difference-k1713
*/

// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairs(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        
        int res=0;
        
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]+k)!=mp.end()){
                res+=mp[arr[i]+k];
            }
            if(mp.find(arr[i]-k)!=mp.end()){
                res+=mp[arr[i]-k];
            }
            
            mp[arr[i]]++;
        }
        
        return res;
    }
};