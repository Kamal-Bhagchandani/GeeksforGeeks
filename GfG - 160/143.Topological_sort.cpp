/*
Question Link: https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/topological-sort
*/

class Solution {
  public:
    void solve(vector<vector<int>>& adj, vector<bool>& visited, int i, stack<int>& st){
        visited[i] = true;
        
        for(int nbr : adj[i]){
            if(!visited[nbr]){
                solve(adj, visited, nbr, st);
            }
        }
        st.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<bool> visited(V, false);
        vector<int> ans;
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                solve(adj, visited, i, st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

