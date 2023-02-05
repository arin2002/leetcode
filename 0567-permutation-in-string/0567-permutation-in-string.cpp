class Solution {
public:
    
    bool cmp(vector<int> &v){
        for(auto it : v){
            if(it != 0)
                return 0;
        }
        
        return 1;
    }
    
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        

        vector<int> v(26,0);
        for(auto it : s1)
            v[it-'a']++;
        
        int i = 0;
        for(int j = 0; j<m; j++){
            v[s2[j]-'a']--;
            
            if(j-i+1 < n)
                continue;
            
            if(cmp(v))
                return 1;
            
            v[s2[i]-'a']++;
            i++;
        }
        
        return 0;
    }
};