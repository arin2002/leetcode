class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.size(), maxi = -1;
        string ans;
        int i = 0, j = 1, k = 2; 
        
        while(k<n){
            if(s[i] == s[j] && s[i] == s[k]){
                
                if(maxi < (s[i]-'0')){
                    ans = string(3, s[i]);
                    maxi = s[i]-'0';
                }
            }
            
            i++; j++; k++;
        }
        
        return ans;
    }
};