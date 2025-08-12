class Solution {
  public:
    string rearrangeString(string s) {
        int hash[26] = {0};  // Space O( 1 )..
        for( int i=0; i<s.length(); i++ ){  // Time O( n )...
            hash[s[i]-'a']++;
        }
    
        int max_freq = 0;
        char max_freq_char;
    
        for( int i=0; i<26; i++ ){  // Time O( 1 )...
            if( hash[i] > max_freq ){
                max_freq = hash[i];
                max_freq_char = i+'a';
            }
        }
    
        if(max_freq > (s.length()+1)/2){
            return "";
        }
        
        int index = 0;
        while( max_freq != 0){  // Time O( n )
            s[index] = max_freq_char;
            max_freq--;
            index+=2;
        }
    
        hash[max_freq_char - 'a'] = 0;
    
    
        for( int i=0; i<26; i++ ){   // Time O( n )...
            while( hash[i] > 0 ){
                index = index < s.length() ? index : 1 ;
                s[index] = i+'a';
                index+=2;
                hash[i]--;
            }
        }
    
        return s;
    }
};