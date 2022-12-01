class Solution {
public:
    
    int f(string &a){
        int count = 0;
        for(auto it : a){
            if(it == 'a'||it == 'e'||it == 'i'||it == 'o'||it == 'u')
                count++;
            
            else if(it == 'A'||it == 'E'||it == 'I'||it == 'O'||it == 'U')
                count++;
        }
        
        return count;
    }
    
    
    bool halvesAreAlike(string s) {
        string a,b;
        
        int n = s.size();
        for(int i = 0; i<n/2; i++){
            a+=s[i];
        }
        
        for(int i = n/2; i<n; i++){
            b+=s[i];
        }
        
        return f(a)==f(b);
            
    }
};