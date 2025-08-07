// Function to return maximum XOR subset in set[]

class Solution {
  public:
    void solve(int arr[], int N, long long &ans, long long tmp, int ind){
        if(ind >= N){
            ans = max(ans, tmp);
            return;
        }
        
        // take
        solve(arr, N, ans, tmp^arr[ind], ind+1);
        // not take 
        solve(arr, N, ans, tmp, ind+1);
        return;
    } 
    
    int maxSubsetXOR(int arr[], int N) {
        // recursive 
        // long long ans = 0;
        // solve(arr, N, ans, 0, 0);
        // return ans;
        
          if(N==0)return 0;
        int x=0;
        while(1){
            int y=*max_element(arr,arr+N);
            if(y==0)return x;
            x=max(x,x^y);
            for(int i=0;i<N;i++){
                arr[i]=min(arr[i],arr[i]^y);
            }
        }
        return x;
    }
};