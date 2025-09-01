class Solution {
  public:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3){
        if(i == s1.length()-1 && j == s2.length()-1){
            if(s1[i] == s3[k] && s2[j] == s3[k+1]){
                return true;
            }else if(s2[j] == s3[k] && s1[i] == s3[k+1]){
                return true;
            }else{
                return false;
            }
        }
        if(i >= s1.length() || j >= s2.length()) return false;
        
        bool tmp1 = false;
        if(s1[i] == s3[k]){
            tmp1 = solve(i+1, j, k+1, s1, s2, s3);
        }
        bool tmp2 = false;
        if(s2[j] == s3[k]){
            tmp2 = solve(i, j+1, k+1, s1, s2, s3);
        }
        
        return tmp1|tmp2;
    }
    
    bool isInterleave(string& s1, string& s2, string& s3) {
        // code here
        // int n1 = s1.length();
        // int n2 = s2.length();
        // int n3 = s3.length();
        // if((n1 + n2) != n3) return false;
        
        // return solve(0, 0, 0, s1, s2, s3);
        
        int l=s1.length(), m=s2.length(), n=s3.length();
        
        if(l+m!=n) return 0;
        
        vector<vector<bool>>v(l+1, vector<bool>(m+1,0));
        
        v[0][0] = 1;
        
        for(int i=0; i<=l; i++){
            for(int j=0; j<=m; j++){
                
                if(i>0 && s1[i-1]==s3[i+j-1]){
                    v[i][j] = v[i][j]||v[i-1][j];
                }
                if(j>0 && s2[j-1]==s3[i+j-1]){
                    v[i][j] = v[i][j]||v[i][j-1];
                }
               
            }
        }
        
        return v[l][m];
        
        
    }
};