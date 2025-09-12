/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-bonus-problems/problem/camelcase-pattern-matching2259
*/

class Solution {
  public:
    vector<string> camelCase(vector<string> &arr, string &pat) {
        // code here
        vector<string> ans;
        
        for(string s : arr){
            int j=0;
            bool valid=true;
            for(char ch:s){
                if('A'<=ch && ch<='Z'){
                    if(j<pat.size() && ch==pat[j]){
                        j++;
                    }
                    else if(j==pat.size()){
                        break;
                    }
                    else{
                        valid=false;
                        break;
                    }
                }
            }
            if(valid && j==pat.size()) ans.push_back(s);
        }
        
        return ans;
    }
};