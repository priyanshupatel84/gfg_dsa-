// User function Template for C++

class Solution {
  public:
    long long divide(long long dividend, long long divisor) {
        
        int sign = ((dividend<0) ^ (divisor<0)) ? -1 : 1;
        
        long long a = abs(dividend);
        long long b = abs(divisor);
        long long  q = 0;
        
        for(int i = 31; i>= 0; --i){
            if((b<<i) <= a){
                a -= b<<i;
                q |= (1LL << i);
            }
        }
        
        return sign*q;
        
    }
};