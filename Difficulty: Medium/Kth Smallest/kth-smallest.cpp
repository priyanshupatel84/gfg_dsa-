// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        
        for(auto it: arr){
            if(pq.size() < k){
                pq.push(it);
            }else if(pq.size() == k && it < pq.top()){
                pq.pop();
                pq.push(it);
            }
        }
        
        return pq.top();
    }
};