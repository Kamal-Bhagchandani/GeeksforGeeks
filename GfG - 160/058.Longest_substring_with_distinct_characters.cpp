/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/longest-distinct-characters-in-string5848
*/

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n=s.size();
        int res=0;
        vector<int> lastIndex(26,-1);
        int start=0;
        for(int end=0;end<n;end++){
            int index = s[end]-'a';
            start = max(start,lastIndex[index]+1);
            res=max(res,end-start+1);
            lastIndex[index]=end;
        }
        return res;
    }
};
