/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-bonus-problems/problem/subarrays-with-k-different-integers
*/

class Solution {
  private:
    int atMostK(vector<int> &arr,int k){
        int n=arr.size();
        int res=0;
        
        int left=0, right=0;
        
        unordered_map<int,int> freq;
        while(right<n){
            freq[arr[right]]++;
            if(freq[arr[right]]==1)
                k--;
                
                while(k<0){
                    freq[arr[left]]-=1;
                    if(freq[arr[left]]==0)
                        k+=1;
                    left++;
                }
            res+= right-left+1;
            right++;
        }
        
        return res;
    }
  public:
    int exactlyK(vector<int> &arr, int k) {
        // code here
        return atMostK(arr,k)-atMostK(arr,k-1);
    }
};