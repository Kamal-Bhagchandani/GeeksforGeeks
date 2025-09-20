/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-bonus-problems/problem/make-array-elements-unique--170645
*/

// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int cnt=0;
        
        int mx=*max_element(arr.begin(),arr.end());
        vector<int> freq(n+mx,0);
        
        for(int val:arr){
            freq[val]++;
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]>1){
                freq[i+1]+=freq[i]-1;
                cnt+=freq[i]-1;
                freq[i]=1;
            }
        }
        
        return cnt;
    }
};