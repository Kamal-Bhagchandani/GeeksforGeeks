/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-bonus-problems/problem/top-k-frequent-elements-in-array
*/

class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int> mp;
        
        for(int it : arr)
            mp[it]++;
            
        priority_queue<pair<int,int>> pq;
        
        for(auto it : mp)
            pq.push({it.second,it.first});
        
        vector<int> ans;
        
        int i = k;
        
        while(!pq.empty()){
            if(i==0) break;
            int value = pq.top().second;
            ans.push_back(value);
            pq.pop();
            i--;
        }
        
        return ans;
    }
};