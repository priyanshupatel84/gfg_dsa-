class Solution {
  public:
    int largestPrimeFactor(int n) {
        // check for 2 as prime 
        int maxprime = 2;
        
        while(n % 2 == 0){
            n = n/2;
        }
        
        for(int i = 3; i*i <= n; i= i+2){
            while(n %i == 0){
                maxprime = max(i, maxprime);
                n = n/i;
            }
        }
        
        if(n > 2){
            maxprime = max(maxprime, n);
        }
        
        return maxprime;
    }
};