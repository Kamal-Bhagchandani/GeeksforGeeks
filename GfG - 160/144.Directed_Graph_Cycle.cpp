/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/detect-cycle-in-a-directed-graph
*/

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 1)
                return true;
                
            if (visited[neighbor] == 0) {
                if (dfs(neighbor, adj, visited))
                    return true;
            }
        }
        visited[node] = 2;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> visited(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
