class Solution {
  public:
    vector<int> topKFrequent(vector<int> &arr, int k) {
        // Your code here
        unordered_map<int, int> mp;
        
        priority_queue<pair<int, int>> pq;
        for(auto it: arr){
            mp[it]++;
        }
        
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        
        vector<int> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
