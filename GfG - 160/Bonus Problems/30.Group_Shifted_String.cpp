/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-bonus-problem/problem/group-shifted-string
*/

class Solution {
  private:
    string getHash(string s){
        int shifts = s[0]-'a';
        for(char &ch : s){
            ch=ch-shifts;
            if(ch<'a'){
                ch+=26;
            }
        }
        
        return s;
    }
  public:
    vector<vector<string>> groupShiftedString(vector<string> &arr) {
        // Your code here
        vector<vector<string>> res;
        
        unordered_map<string,int> mp;
        
        for(string s:arr){
            string hash = getHash(s);
            if(mp.find(hash)==mp.end()){
                mp[hash] = res.size();
                res.push_back({});
            }
            res[mp[hash]].push_back(s);
        }
        
        return res;
    }
};