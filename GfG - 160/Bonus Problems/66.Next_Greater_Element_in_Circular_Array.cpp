/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-bonus-problems/problem/next-greater-element
*/

class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n=arr.size();
        stack<int> st;
        
        vector<int> res(n,-1);
        
        for(int i = 2*n-1; i >= 0; i--){
            while(!st.empty() and st.top()<=arr[i % n])
                st.pop();
            
            if(!st.empty() && i < n)
                res[i]=st.top();
            
            st.push(arr[i % n]);
        }
        
        return res;
    }
};