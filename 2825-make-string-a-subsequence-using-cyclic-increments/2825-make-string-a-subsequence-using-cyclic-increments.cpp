class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size(), i = 0, j = 0;
        
        while(i<n && j<m){
            if(s[i] == t[j]){
                j++;
            }
            else{
                char next = (s[i]-'a')%26 + 1+'a';
                
                if(next == 123)
                    next = 'a';
                cout<<s[i]<<" "<<next<<endl;
                if(next == t[j])
                    j++;
            }
            
            i++;
        }
        
        return j == m;
    }
};