class Solution {
  public:
    bool dfs(int node, vector<int> &vis, vector<int> adj[], int par){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, adj, node) == true)
                    return true;
            }else if(vis[it] && it != par){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        vector<int> vis(V, 0);
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, vis, adj, -1) == true) return true;
            }
        }
        
        return false;
    }
};