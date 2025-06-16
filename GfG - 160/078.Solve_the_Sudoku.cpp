/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/solve-the-sudoku-1587115621
*/

class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isSafe(vector<vector<int>>& mat,int i, int j, int num,
        vector<int>& row, vector<int>& col, vector<int>& box){
        
        if( (row[i]&(1<<num)) || (col[j]&(1<<num)) || 
                            (box[i/3*3+j/3]&(1<<num)) ){
            return false;
        }
        return true;
    }
    
    bool sudokuSolver(vector<vector<int>>& mat,int i, int j,
        vector<int>& row, vector<int>& col, vector<int>& box){
        
        int n=mat.size();
        if(i==n-1 && j==n)
            return true;
        
        if(j==n){
            i++;
            j=0;
        }
        
        if(mat[i][j]!=0){
            return sudokuSolver(mat,i,j+1,row,col,box);
        }
        
        for(int num=1;num<n+1;num++){
            if (isSafe(mat,i,j,num,row,col,box)){
                mat[i][j]=num;
                row[i] |= (1<<num);
                col[j] |= (1<<num);
                box[(i/3)*3+j/3] |= (1<<num);
                
                if(sudokuSolver(mat,i,j,row,col,box))
                    return true;
                    
                mat[i][j]=0;
                row[i] &= ~(1<<num);
                col[j] &= ~(1<<num);
                box[(i/3)*3+j/3] &= ~(1<<num);
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<int> row(n,0), col(n,0), box(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=0){
                    row[i] |= (1<<mat[i][j]);
                    col[j] |= (1<<mat[i][j]);
                    box[(i/3)*3+j/3] |= (1<<mat[i][j]);
                }
            }
        }
        sudokuSolver(mat,0,0,row,col,box);
    }
};