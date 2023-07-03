class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n = s.length(), m = t.length();
        
        if(n!=m)
            return 0;
        
        unordered_map<char,int> ump;
        if(s == t){
            for(int i = 0; i<n; i++){
                if(ump.find(s[i]) != ump.end())
                    return 1;
                
                ump[s[i]]++;
            }
            
            return 0;
        }
        int ind1 = -1,  ind2 = -1;
        
        for(int i = 0; i<n; i++){
            if(s[i] != t[i])
            {
                if(ind1 == -1)
                    ind1 = i;
                else if(ind2 == -1)
                    ind2 = i;
            }
        }
        
        if(ind1 == -1 || ind2 == -1)
            return 0;
        
        swap(s[ind1],s[ind2]);
        return s==t;
    }
};