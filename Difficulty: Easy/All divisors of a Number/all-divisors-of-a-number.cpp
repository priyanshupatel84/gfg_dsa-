class Solution {
  public:
    void print_divisors(int n) {
        for(int i = 1; i<= n/2; i++){
            if(n%i == 0){
                cout << i << " ";
            } 
        }
        
        cout << n;
    }
};