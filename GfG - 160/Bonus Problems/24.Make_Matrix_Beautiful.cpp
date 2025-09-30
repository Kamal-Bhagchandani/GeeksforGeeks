/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-bonus-problem/problem/make-matrix-beautiful-1587115620
*/

class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int res = 0, rows = mat.size(), maxi = 0;
        
        for(int i=0; i<rows; i++){
            int rowsum = 0, colsum = 0;
            for(int j = 0;j < rows; j++){
                rowsum += mat[i][j];
                res += mat[i][j];
                colsum += mat[j][i];
            }
            maxi = max({colsum, maxi, rowsum});
        }
        return rows * maxi - res;
    }
};