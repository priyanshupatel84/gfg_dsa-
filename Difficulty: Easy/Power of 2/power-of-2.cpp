class Solution {
  public:
    bool isPowerofTwo(int n) {
        // code here
        if(n > 0 && (n & (n-1)) == 0){
            return true;
        }
        return false;
    }
};