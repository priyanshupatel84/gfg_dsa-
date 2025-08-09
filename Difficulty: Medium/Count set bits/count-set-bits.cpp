class Solution {
  public:
    int powerof2(int n){
        int x = 0;
        while(1<<x <= n){
            x++;
        }
        return x-1;
        
    }
    int countSetBits(int n) {
        if(n == 0) return 0;
        int x = powerof2(n);
        
        int a = (1<<(x-1))*x;
        int b = n-(1<<x);
        
        return a+b+1+countSetBits(b);
    }
};
