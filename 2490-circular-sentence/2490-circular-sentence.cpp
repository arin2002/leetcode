class Solution {
public:
    bool isCircularSentence(string s) {
        
        int n = s.size();
        
        if(s[n-1] != s[0])
            return false;
        
        for(int i = 0; i<n; i++){  
            
            while(i+1<n && s[i+1] != ' '){
                i++;
            }
            
            if(i+2<n && s[i] != s[i+2]){
                cout<<s[i]<<" "<<s[i+2]<<endl;
                return false;
            }
            
            i++;
        }
        
        
        return true;
    }
};