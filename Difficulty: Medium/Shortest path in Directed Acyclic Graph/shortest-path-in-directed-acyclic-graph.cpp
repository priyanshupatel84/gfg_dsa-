// User function Template for C++
class Solution {
  public:
    void dfs_topo(int node, stack<int> & st, vector<pair<int, int>> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                dfs_topo(it.first, st, adj, vis);
            }
        }
        
        st.push(node);
        return;
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, int>> adj[V];
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v, w});
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs_topo(i, st, adj, vis);
            }
        }
        
        vector<int> dis(V, 1e9);
        dis[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                if(dis[node] + it.second < dis[it.first]){
                    dis[it.first] = dis[node] + it.second;
                }
            }
            
        }
        
        for(auto &it : dis){
            if(it == 1e9) it = -1;
        }
        
        return dis;
    }
};
