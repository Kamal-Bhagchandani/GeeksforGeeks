/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/subarrays-with-at-most-k-distinct-integers
*/

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int res=0;
        unordered_map<int,int> mp;
        int left=0, right=0;
        
        while(right<n){
            mp[arr[right]]++;
            
            if(mp[arr[right]]==1)
                k--;
                
            while(k<0){
                mp[arr[left]]--;
                if(mp[arr[left]]==0)
                    k++;
                left++;
            }
            res += right-left+1;
            right++;
        }
        
        return res;
    }
};