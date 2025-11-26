/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-bonus-problems/problem/minimum-cost-of-ropes-1587115620
*/

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int val : arr){
            pq.push(val);
        }
        
        int cost=0;
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int cur = first+second;
            cost += cur;
            pq.push(cur);
        }
        
        return cost;
    }
};