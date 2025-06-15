/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/n-queen-problem0315
*/

// User function Template for C++

class Solution {
  public:
    void nQueenUtil(int j,int n,vector<bool>& rows,vector<bool>& diag1,
        vector<bool>& diag2,vector<int>& board,vector<vector<int>>& res){
            if (j>n){
                res.push_back(board);
                return;
            }    
            for(int i=1;i<n+1;i++){
                if (!rows[i] && !diag1[i-j+n] && !diag2[i+j]){
                    rows[i]=diag1[i-j+n]=diag2[i+j]=true;
                    board.push_back(i);
                    nQueenUtil(j+1,n,rows,diag1,diag2,board,res);
                    rows[i]=diag1[i-j+n]=diag2[i+j]=false;
                    board.pop_back();
                }
            }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<bool> rows(n+1,false);
        vector<bool> diag1(2*n+1,false);
        vector<bool> diag2(2*n+1,false);
        vector<vector<int>> res;
        vector<int> board;
        nQueenUtil(1,n,rows,diag1,diag2,board,res);
        return res;
    }
};