class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string st;
        
        for(int i = 0; i<n-1; i++){
            st += s[i];
            
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