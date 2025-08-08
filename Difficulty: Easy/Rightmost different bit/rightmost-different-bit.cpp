class Solution {
  public:
    int posOfRightMostDiffBit(int m, int n) {
        //  code here
        int i = 1;
        if(n == m)return -1;
        if(m > n){
            swap(m, n);
        }
        
        while(n > 0 && m >= 0){
            int f = n&1;
            int s = m&1;
            if(f == s){
                i++;
                n = n >>1;
                m = m>>1;
            }else if(f != s){
                return i;
            }
        }
        
        return i;
    }
};