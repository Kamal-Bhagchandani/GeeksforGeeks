/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/implementing-dijkstra-set-1-adjacency-matrix
*/

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dis(V, INT_MAX);
        dis[src] = 0;
        
        vector<vector<pair<int, int>>> adj(V);
        for(auto z : edges){
            adj[z[0]].push_back({z[1], z[2]});
            adj[z[1]].push_back({z[0], z[2]});
        }
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            
            for(auto x : adj[ele.first]){
                int w = x.second;
                if((dis[ele.first]+ w)< dis[x.first]){
                    dis[x.first] = dis[ele.first]+ w;
                    q.push({x.first, dis[x.first]});
                }
            }
            
        }
        return dis;
    }
};
