class Solution {
public:
    int compareVersion(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
    
        while(i<n || j<m){
            // string a = "0", b = "0";
            int a = 0, b = 0;
            
            while(i<n && s[i] != '.'){   
                a = a*10 + (s[i++]-'0');
            }
        
            while(j<m && t[j] != '.'){
                b = b*10 + (t[j++]-'0');
            }
            
            if(a > b){
                return 1;
            }
            else if(b > a){
                return -1;
            }
            
            i++;
            j++;
        }
                        
        return 0;
    }
};