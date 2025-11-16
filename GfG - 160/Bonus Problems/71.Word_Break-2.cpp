/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dp-bonus-problems/problem/word-break-part-23249
*/

// User function Template for C++
class Solution {
  public:
    vector<string> wordBreak(vector<string>& dict, string& s) {
        // code here
        unordered_set<string> st(dict.begin(),dict.end());
        int n = s.size();
        
        vector<vector<string>> dp(n+1);
        
        dp[n]={""};
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i + 1; j <= n; j++){
                string word = s.substr(i, j-i);
                
                if(st.count(word)){
                    for(string &sub : dp[j]){
                        if(sub.empty())
                            dp[i].push_back(word);
                        else
                            dp[i].push_back(word + " " + sub);
                    }
                }
            }
        }
        
        return dp[0];
    }
};