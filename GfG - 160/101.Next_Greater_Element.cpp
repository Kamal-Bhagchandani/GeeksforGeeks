/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/next-larger-element-1587115620
*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> res(n,-1);
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            
            if(!st.empty())
                res[i]=st.top();
                
            st.push(arr[i]);
        }
        
        return res;
    }
};