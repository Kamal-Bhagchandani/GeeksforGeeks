/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/stock-span-problem-1587115621
*/

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n=arr.size();
        vector<int> res(n,0);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i])
                st.pop();
            if(!st.empty())
                res[i]=i-st.top();
            else
                res[i]=i+1;
            st.push(i);
        }
        return res;
    }
};