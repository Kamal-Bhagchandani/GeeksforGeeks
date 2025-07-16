/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-gfg-160/problem/maximum-of-all-subarrays-of-size-k3101
*/

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        if(k==1)
            return arr;
            
        vector<int> res;
        deque<int> dq(k);
        
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        for(int i=k;i<arr.size();i++){
            res.push_back(arr[dq.front()]);
            
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
                
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back();
                
            dq.push_back(i);
        }
        
        res.push_back(arr[dq.front()]);
        
        return res;
    }
};