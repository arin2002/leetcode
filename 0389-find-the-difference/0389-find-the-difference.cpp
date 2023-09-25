class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26);
        int n = s.size(), m = t.size();
        for(int i = 0; i<n; i++){
            v[s[i]-'a']++;
        }
        
        for(int i = 0; i<m; i++){
            v[t[i]-'a']--;
            
            if(v[t[i]-'a'] < 0){
                return t[i];
            }
        }
        
        return '-1';
    }
};