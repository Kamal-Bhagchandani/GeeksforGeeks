/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-bonus-problems/problem/bipartite-graph
*/

class Solution {
  private:
    vector<vector<int>> constructadj(int V, vector<vector<int>> &edges){
        vector<vector<int>> adj(V);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return adj;
    }
    bool dfs(int u, int color, vector<int> &colors, vector<vector<int>> &adj){
        colors[u] = color;
        
        for(auto &v : adj[u]){
            if(colors[v] == -1){
                if(!dfs(v, 1 - color, colors, adj))
                    return false;
            }
            else if(colors[v] == color){
                return false;
            }
        }
        
        return true;
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> colors(V,-1);
        vector<vector<int>> adj = constructadj(V,edges);
        
        for(int i = 0; i < V; i++){
            if(colors[i] == -1){
                if(!dfs(i, 0, colors, adj))
                    return false;
            }
        }
        
        return true;
    }
};