/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-string-chain
*/

class Solution {
  public:
    bool static cmp(const string &a, const string &b){
        return a.size()<b.size();
    }
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int> dp;
        
        int res=1;
        
        for(const string &w : words){
            dp[w]=1;
            for(int i=0;i<w.size();i++){
                string pred = w.substr(0,i)+w.substr(i+1);
                
                if (dp.find(pred) != dp.end()){
                    dp[w] = max(dp[w],dp[pred]+1);
                }
            }
            
            res = max(res,dp[w]);
        }
        
        return res;
    }
};