class Solution {
  public:
    vector<int> threeDivisors(vector<long long> query, int q) {
        // Write your code here
        long long maxi = 0;
        for(auto it : query){
            maxi = max(maxi, it);
        }
        
        vector<int> isPrime(maxi+1, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        
        for(long long i = 2; i*i<=maxi; i++){
            if(isPrime[i]){
                for(long long j = i*i; j<=maxi; j= j+i){
                    isPrime[j] = 0;
                }
            }
        }
        
        vector<int> results;
        vector<long long> temp;
    
        for(long long i = 2; i*i<=maxi; i++){
            if(isPrime[i]){
                temp.push_back(i*i);
            }
        }
        
        for(auto it: query){
            int count = upper_bound(temp.begin(), temp.end(), it) - temp.begin();
            results.push_back(count);
        }
        
        return results;
    }
};