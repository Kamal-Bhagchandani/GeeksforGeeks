/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/permutations-of-a-given-string2041
*/

class Solution {
  public:
    void permutation(int n,string& curr, 
                unordered_map<char,int> &cnt,vector<string>& res){
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(pair<char,int> it:cnt){
            char c = it.first;
            int count=it.second;
            if(count==0){
                continue;
            }
            curr.push_back(c);
            cnt[c]--;
            permutation(n,curr,cnt,res);
            curr.pop_back();
            cnt[c]++;
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here
        vector<string> res;
        unordered_map<char,int> cnt;
        for(char ch : s)
            cnt[ch]++;
        string curr="";
        permutation(s.size(),curr,cnt,res);
        return res;
    }
};
