/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-bonus-problems/problem/rearrange-characters4649
*/

class Solution {
  public:
    string rearrangeString(string s) {
        // code here
        int n = s.size();
        
        unordered_map<char,int> freq;
        
        for(char ch : s) freq[ch]++;
        
        priority_queue<pair<int,char>> pq;
        for(char c = 'a'; c <= 'z'; c++){
            if(freq[c] > 0)
                pq.push({freq[c],c});
        }
        
        string res = "";
        
        pair<int,char> prev = {-1,'#'};
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            res.push_back(p.second);
            
            if(prev.first > 0)
                pq.push(prev);
            
            p.first--;
            prev = p;
        }
        
        return (res.size() != n)? "" : res;
    }
};