/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/detect-cycle-in-an-undirected-graph
*/

class Solution {
  public:
    bool dfs(int i, int p, vector<vector<int>>& adj, vector<bool>& vis){
        vis[i] = true;
        for(int neighbor : adj[i]){
            if(!vis[neighbor]){
                if(dfs(neighbor,i,adj,vis))
                    return true;
            }
            else if(neighbor!=p)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto& edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(V, false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i,-1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

