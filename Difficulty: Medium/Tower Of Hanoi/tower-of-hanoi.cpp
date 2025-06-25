class Solution {
  public:
    // You need to complete this function
    int count = 0;
    int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        if(n == 0) return count;
        towerOfHanoi(n-1, from, aux, to);
        
        count++;
        towerOfHanoi(n-1, aux, to, from);
        return count;
    }
};