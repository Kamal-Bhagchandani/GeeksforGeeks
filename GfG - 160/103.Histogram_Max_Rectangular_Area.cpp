/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/maximum-rectangular-area-in-a-histogram-1587115620
*/

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int> s;
        int res=0;
        int tp,curr;
        
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                tp=s.top();
                s.pop();
                int width = s.empty() ? i : i-s.top()-1;
                res=max(res,arr[tp]*width);
            }
            s.push(i);
        }
        
        while(!s.empty()){
            tp=s.top();
            s.pop();
            curr=arr[tp]*(s.empty()? n : n-s.top()-1);
            res=max(res,curr);
        }
        return res;
    }
};
