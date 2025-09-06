/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/finding-the-numbers0215
*/

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int n=arr.size();
        int s1=0, s2=0;
        int x=0;
        
        for(int val : arr){
            x^=val;
        }
        
        x=(x&(-x));
        
        for(int i=0;i<n;i++){
            if((arr[i]&x)==x) 
                s1^=arr[i];
            else
                s2^=arr[i];
        }
        
        if(s1>s2) swap(s1,s2);
        
        return {s1,s2};
    }
};