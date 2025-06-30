class Solution {
  public:
    int setBits(int n) {
        int set = 0;
        while(n > 0){
            if(n&1) set++;
            n = n>>1;
        }
        
        return set;
    }
};