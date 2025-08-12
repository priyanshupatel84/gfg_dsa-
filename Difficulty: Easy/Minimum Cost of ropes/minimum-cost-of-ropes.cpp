class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        if(arr.size() == 1) return 0;
        
        priority_queue<int , vector<int>, greater<int>> pq;
        
        for(auto it : arr){
            pq.push(it);
        }
        
        int cost = 0;
        while(pq.size() > 1){
            int fir = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();
            
            int fin = fir+sec;
            cost += fin;
            pq.push(fin);
        }
        
        
        return cost;
    }
};