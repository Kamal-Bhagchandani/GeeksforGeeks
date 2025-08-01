/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-gfg-160/problem/longest-bounded-difference-subarray
*/

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        deque<int> minQueue,maxQueue;
        
        int n=arr.size(),start = 0,end = 0;
        int resStart=0, resEnd=0;
        
        while(end<n){
            while(!minQueue.empty() && arr[minQueue.back()]>arr[end])
                minQueue.pop_back();
            while(!maxQueue.empty() && arr[maxQueue.back()]<arr[end])
                maxQueue.pop_back();
                
            minQueue.push_back(end);
            maxQueue.push_back(end);
            while(arr[maxQueue.front()]-arr[minQueue.front()]>x){
                if(start==minQueue.front())
                    minQueue.pop_front();
                if(start==maxQueue.front())
                    maxQueue.pop_front();
                start++;
            }
            if(end-start > resEnd - resStart){
                resStart=start;
                resEnd=end;
            }
            end++;
        }
        vector<int> res;
        for(int i=resStart; i<=resEnd;i++)
            res.push_back(arr[i]);
        return res;
    }
};