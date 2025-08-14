/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/maximize-partitions-in-a-string
*/

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n=s.size();
        int till=-1,partition=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) mp[s[i]]=i;
        for(int i=0;i<n;i++){
            till=max(till,mp[s[i]]);
            if(i==till) partition++;
        }
        return partition;
    }
};