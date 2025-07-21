/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-palindromic-subsequence-1612327878
*/

// User function Template for C++

class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        int n=s.size();
        
        vector<int> curr(n),prev(n);
        for(int i=n-1;i>=0;i--){
            curr[i]=1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    curr[j]=prev[j-1]+2;
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return curr[n-1];
    }
};