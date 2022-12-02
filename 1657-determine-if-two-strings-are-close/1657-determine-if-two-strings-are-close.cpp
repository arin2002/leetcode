class Solution {
public:
    bool closeStrings(string s, string t) {
        int n=s.size(), m = t.size();
        
        if(n!=m)
            return 0;
        
        unordered_map<int,int> ump1,ump2;
        for(int i = 0; i<n; i++){
            ump1[s[i]]++;
            ump2[t[i]]++;
        }
        
        for(int i = 0; i<n; i++){
            if(ump1.find(t[i]) == ump1.end())
                return 0;
            
            if(ump2.find(s[i]) == ump2.end())
                return 0;
        }
        
        vector<int> v1,v2;
        for(auto [i,j] : ump1){
            v1.push_back(j);
        }
        
        for(auto [i,j] : ump2){
            v2.push_back(j);
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return v1==v2;
    }
};