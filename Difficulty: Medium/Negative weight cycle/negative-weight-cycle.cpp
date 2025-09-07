class Solution {
  public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        // using bellmen ford 
        vector<int> dis(n, 1e9);
        int m = edges.size();
        
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if( dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                }
            }
        }
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                
                if(dis[u] + w < dis[v]){
                    return 1;
                }
            }
        }
        return 0;
        
    }
};