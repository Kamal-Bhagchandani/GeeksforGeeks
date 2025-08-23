/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/articulation-point2616
*/

class Solution {
  private:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc,int& time,
             vector<int>& low,vector<bool>& vis, vector<bool>& isArticulation){
        vis[u]=true;
        disc[u] = low[u]=time++;
        int children = 0;
        
        for(int v : adj[u]){
            if(!vis[v]){
                children++;
                dfs(v,u,adj,disc,time,low,vis,isArticulation);
                low[u]=min(low[u],low[v]);
                if(parent!=-1 && low[v]>=disc[u])
                    isArticulation[u]=true;
            }
            else if(v!=parent)
                low[u]=min(low[u],disc[v]);
        }
        if(parent == -1 && children>1)
            isArticulation[u]=true;    
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        
        for(vector<int> edge : edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> disc(V,-1), low(V,-1);
        vector<bool> vis(V,false), isArticulation(V,false);
        int time=0;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, -1, adj, disc, time, low, vis, isArticulation);
            }
        }
        vector<int> res;
        for(int i=0;i<V;i++){
            if(isArticulation[i]){
                res.push_back(i);
            }
        }
        if (res.empty()) return {-1};
        return res;
    }
};