/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/depth-first-traversal-for-a-graph
*/

class Solution {
  public:
    void dfsRec(int i,vector<int>& vis,vector<int>& res,
                vector<vector<int>>& adj){
        vis[i]=true;
        res.push_back(i);
        for(int x:adj[i]){
            if(!vis[x])
                dfsRec(x,vis,res,adj);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> vis(n,false);
        vector<int> res;
        
        dfsRec(0,vis,res,adj);
        
        return res;
    }
};