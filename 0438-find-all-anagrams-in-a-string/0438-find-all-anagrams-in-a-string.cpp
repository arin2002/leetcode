class Solution {
public:
    
    bool cmp(vector<int> &v){
        for(auto it :v){
            if(it != 0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        
        if(n<m)
            return ans;
        
        vector<int> v(27,0);
        
        for(auto &it :p)
            v[it-'a']++;
        
        int i = 0, j = 0;
        while(j<n){
            v[s[j]-'a']--;
            if(j-i+1 < m){
                j++;
                continue;
            }
            
            if(cmp(v))
                ans.push_back(i);
            
            v[s[i]-'a']++;
            i++;
            j++;
        }

        return ans;
    }
};