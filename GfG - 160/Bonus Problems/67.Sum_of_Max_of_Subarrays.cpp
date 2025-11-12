/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-bonus-problems/problem/sum-of-max-of-subarrays
*/

class Solution {
  public:
    int sumOfMax(vector<int> &arr) {
        // code here
        int n = arr.size();
        int res = 0;
        stack<int> st;
        vector<int> left(n),right(n);
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()]<arr[i])
                st.pop();
            
            left[i] = st.empty()? i + 1 : i - st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            
            right[i] = st.empty()? n - i : st.top() - i;
            st.push(i);
        }
        
        for(int i = 0; i < n; i++){
            res += arr[i] * left[i] * right[i];
        }
        
        return res;
    }
};