/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/min-subsets-with-consecutive-numbers0601
*/

class Solution {
  public:
    int numOfSubset(vector<int> &arr) {
        // Your code goes here
        set<int> st;
        int res=0;
        
        for(int val:arr){
            st.insert(val);
        }
        for(int val:arr){
            if(st.find(val-1)==st.end()) res++;
        }
        
        return res;
    }
};