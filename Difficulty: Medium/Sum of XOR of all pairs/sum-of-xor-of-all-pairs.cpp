

class Solution {
  public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n) {
        long long int sum = 0;
        for(int i = 0; i<32; i++){
            int cnt_z = 0, cnt_o = 0;
            
            for(int j = 0; j<n; j++){
                if((arr[j])&(1<<i)){
                    cnt_o++;
                }else{
                    cnt_z++;
                }
            }
            sum += (long long int)(1<<i)*cnt_o*cnt_z;
        }
        
        return sum;
    }
};