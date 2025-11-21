/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dp-bonus-problems/problem/palindromic-patitioning4845
*/

// User function Template for C++

class Solution {
  private:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int palPartitionRec(string &s, int i, int j, vector<vector<int>> &memo){
        if(i >= j)
            return 0;
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        if(isPalindrome(s,i,j))
            return 0;
        
        int res = INT_MAX;
        int cuts;
        
        for(int k = i; k < j; k++){
            cuts = 1 + palPartitionRec(s, i, k, memo) + 
                       palPartitionRec(s, k + 1, j, memo);
            res = min(res,cuts);
        }
        
        return memo[i][j] = res;
    }
  public:
    int palPartition(string &s) {
        // code here
        int n = s.size();
        
        vector<vector<int>> memo(n, vector<int>(n,-1));
        
        return palPartitionRec(s, 0, n - 1, memo);
    }
};