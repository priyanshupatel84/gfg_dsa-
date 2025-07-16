class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int,int>> adj[n+1];

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
    
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1,-1);
        dist[1]=0;
        pq.push({0,1});
    
        while(!pq.empty()){
            int curr=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
    
            for(auto neigh:adj[curr]){
                if(dist[curr]+neigh.second<dist[neigh.first]){
                    parent[neigh.first]=curr;
                    dist[neigh.first]=dist[curr]+neigh.second;
                    pq.push({dist[neigh.first],neigh.first});
                }
            }
        }
        
        if(dist[n]==INT_MAX) return {-1};
        
        
        vector<int>path;
        int i=n;
        while(parent[i]!=-1){
            path.push_back(i);
            i=parent[i];
        }
        
        path.push_back(1);
        
        vector<int>ans;
        ans.push_back(dist[n]);
        for(auto i:path) ans.push_back(i);
        
        return ans;
    }
        
};