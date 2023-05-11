class Solution {
public:
    
    bool check(char c){
        return !isalpha(c);
    }
    
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size()-1;
        
        while(l<r){
            while(l<r &&check(s[l])){
                l++;
            }
            
            while(l<r &&check(s[r]))
                r--;
            
            if(r<l)
                break;
            
            swap(s[l++],s[r--]);
        }
        
        return s;
    }
};