/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/minimum-removals-for-target-sum
*/

class Solution {
  public:
    int minRemovals(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        int left=0, currSum=0, maxLen=-1;
        
        int total = accumulate(arr.begin(),arr.end(),-k);
        if(!total) return n;
        
        for(int right=0;right<n;right++){
            currSum+=arr[right];
            
            while(left<right && currSum>total){
                currSum-=arr[left];
                left++;
            }
            if(currSum==total){
                maxLen = max(maxLen, right-left+1);
            }
        }
        
        return maxLen==-1? -1 : n-maxLen;
    }
};