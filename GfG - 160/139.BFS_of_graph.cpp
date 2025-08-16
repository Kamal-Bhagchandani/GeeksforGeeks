/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bfs-traversal-of-graph
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        
        queue<int> q;
        vector<int> res;
        vector<bool> vis(n,false);
        
        q.push(0);
        vis[0]=true;
        
        while(!q.empty()){
            int i=q.front();
            q.pop();
            res.push_back(i);
            for(int val:adj[i]){
                if(vis[val]==false){
                    q.push(val);
                    vis[val]=true;
                }
            }
        }
        return res;
    }
};