/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/total-decoding-messages1235
*/

class Solution {
  public:
    int recFunc(int i,int n,string &digits,vector<int> &memo){
        if(i==n) return 1;
        if(memo[i]!=-1){
            return memo[i];
        }
        int res=0;
        if(digits[i]!='0')
            res = recFunc(i+1,n,digits,memo);
        if(i+1<n && (digits[i]=='1' || (digits[i]=='2' && digits[i+1]<='6')))
            res += recFunc(i+2,n,digits,memo);
        memo[i]=res;
        return memo[i];
    }
    int countWays(string &digits) {
        // Code here
        int n=digits.size();
        vector<int> memo(n,-1);
        memo[0]=recFunc(0,n,digits,memo);
        
        return memo[0];
    }
};