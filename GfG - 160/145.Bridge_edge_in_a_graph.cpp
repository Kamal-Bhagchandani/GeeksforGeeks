/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bridge-edge-in-graph
*/

class Solution {
  public: 
    void dfs(int node,vector<int> adj[],int c, int d,vector<bool>& vis){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it] && !(node==c && it==d)){
                dfs(it,adj,c,d,vis);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // code here
        vector<int> adj[V];
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(V,false);
        dfs(c,adj,c,d,vis);
        return !vis[d];
    }
};
