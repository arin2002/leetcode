class Solution {
public:
    
    bool cmp(vector<int> v){
        for(auto it: v){
            if(it > 1)
                return 0;
        }
        
        return 1;
    }
    
    
    int countGoodSubstrings(string s) {
        int i = 0, ans = 0;
        vector<int> v(26);
        for(int j = 0; j<s.size(); j++){
            v[s[j]-'a']++;
                
            if(j-i+1 < 3)
                continue;
            
            if(cmp(v))
                ans++;
            
            v[s[i]-'a']--;
            i++;
        }
        
        return ans;
    }
};