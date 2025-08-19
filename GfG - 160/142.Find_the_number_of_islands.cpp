/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/find-the-number-of-islands
*/

class Solution {
  public:
    void dfs(int r, int c, vector<vector<char>>& grid, int n, int m, bool vis[][501]){
        vis[r][c]=true;
        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if(j!=0 || i!=0){
                    if (r+i<n && r+i>=0 && c+j<m && c+j>=0){
                        if(vis[r+i][c+j]==false && grid[r+i][c+j]=='L'){
                            dfs(r+i,c+j,grid,n,m,vis);
                        }
                    }
                }
            }
        }
        
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0,n=grid.size(),m=grid[0].size();
        bool vis[n][501];
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                vis[i][j]=false;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='L'){
                    ans++;
                    dfs(i,j,grid,n,m,vis);
                }
            }
        }
        return ans;
    }
};
