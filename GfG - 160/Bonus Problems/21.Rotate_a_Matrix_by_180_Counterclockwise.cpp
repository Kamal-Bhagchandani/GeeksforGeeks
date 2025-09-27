/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/c-matrix-rotation-by-180-degree0745
*/

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(mat[i][j],mat[n-1-i][n-1-j]);
            }
        }
        if(n%2==1){
            reverse(mat[n/2].begin(),mat[n/2].end());
        }
    }
};