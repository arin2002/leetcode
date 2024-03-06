class Solution {
public:
    int minimumLength(string s) {
        int l = 0, n = s.size(), r = n-1;
        
        while(l<r && s[l] == s[r]){
            char c = s[l];
            
            while(l<=r && s[l] == s[r])
                l++;
            
            while(l<=r && c == s[r]){
                r--;
            } 
        }
        
        return r-l+1;
    }
};