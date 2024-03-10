class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string st;
        
        for(int i = n/2; i>=1; i--){
            
            st = s.substr(0,i);
            string t;
            
            if(n%(st.size()) != 0)
                continue;
            
            for(int j = 0; j<n/st.size(); j++){
                t += st;
            }
            
            if(t == s)
                return 1;
        }
        
        return 0;
    }
};