class Solution {
public:
    int compareVersion(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
    
        while(i<n || j<m){
            string a = "0", b = "0";
            
            while(i<n && s[i] != '.'){   
                a += s[i++];
            }
        
            while(j<m && t[j] != '.'){
                b += t[j++];
            }
            
            int c = stoi(a), d = stoi(b);
            
            if(c > d){
                return 1;
            }
            else if(d > c){
                return -1;
            }
            
            i++;
            j++;
        }
        
//         while(i<n){
//             if(s[i++] > '0')
//                 return 1;
//         }
        
//         while(j<m){
//             if(t[j++] > '0')
//                 return -1;
//         }
                
        return 0;
    }
};