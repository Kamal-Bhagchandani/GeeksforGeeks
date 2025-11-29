/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-bonus-problems/problem/connected-components-in-an-undirected-graph
*/

class Solution {
  private:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &component){
        visited[node] = true;
        component.push_back(node);
        
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited, component);
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V,false);
        vector<vector<int>> res;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i, adj, visited, component);
                res.push_back(component);
            }
        }
        
        return res;
    }
};
