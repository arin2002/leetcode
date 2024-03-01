class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), count = -1;
        
        for(auto &it: s){
            if(it == '1'){
                count++;
            }
            
            it = '0';
        }
        
        s[n-1] = '1';
        
        for(int i = 0; i<count; i++){
            s[i] = '1';
        }
        
        return s;
    }
};