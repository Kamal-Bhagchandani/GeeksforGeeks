/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/maximum-of-minimum-for-every-window-size3453
*/

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        vector<int> res(n,0);
        stack<int> st;
        vector<int> len(n,0);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int top = st.top();
                st.pop();
                int windowSize = st.empty()? i : i-st.top()-1;
                len[top] = windowSize;
            }
            st.push(i);
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            int windowSize = st.empty()? n : n-st.top()-1;
            len[top] = windowSize;
        }
        for(int i=0;i<n;i++){
            int windowSize = len[i]-1;
            res[windowSize] = max(res[windowSize],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            res[i] = max(res[i],res[i+1]);
        }
        return res;
    }
};