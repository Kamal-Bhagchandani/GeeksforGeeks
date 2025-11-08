/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-bonus-problems/problem/nearly-sorted-1587115620
*/

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        priority_queue<int, vector<int>,greater<int>> pq;
        
        for (int i=0; i <= k; i++) {
            pq.push(arr[i]);
        }
        
        int index = 0;
        
        for (int i = k+1; i < n; i++) {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while (!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};