class Solution {
public:
    int solve(string &s){
        int l = 0, r = s.size()-1;
        
        while(l<r){
            if(s[l++] != s[r--])
                return 0;
        }
        
        return 1;
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            string t;
            for(int j = i; j<s.size(); j++){
                t += s[j];
                if(solve(t))
                    ans++;
            }
        }
        
        return ans;
    }
};