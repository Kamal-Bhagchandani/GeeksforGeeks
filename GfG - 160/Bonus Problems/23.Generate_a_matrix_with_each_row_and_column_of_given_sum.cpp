/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/generate-a-matrix-with-each-row-and-column-of-given-sum
*/

// User function template for C++

class Solution {
  public:
    vector<vector<int>> generateMatrix(vector<int> rowSum, vector<int> colSum) {
        // code here
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>> res(n,vector<int>(m));
        
        int i=0,j=0;
        while(i<n && j<m){
            res[i][j]=min(rowSum[i],colSum[j]);
            
            rowSum[i]-=res[i][j];
            colSum[j]-=res[i][j];
            
            if(rowSum[i]==0) i++;
            if(colSum[j]==0) j++;
        }
        
        return res;
    }
};