/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-bonus-problems/problem/the-celebrity-problem
*/

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        
        int i = 0, j = n - 1;
        
        while(i<j){
            if(mat[j][i])
                j--;
            else
                i++;
            
        }
        int c = i;
        
        for(i = 0; i < n; i++){
            if(i == c) continue;
            
            if(mat[c][i] || !mat[i][c])
                return -1;
        }
        
        return c;
    }
};