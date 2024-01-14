class Solution {
public:
    bool closeStrings(string s, string t) {
        int n = s.size(), m = t.size();
        
        if(n != m)
            return 0;
        
        /*
             aabbcc
             abbccc
        */
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        
        // if(s == t)
        //     return 1;
        
        vector<int> v1(26), v2(26);
        unordered_set<char> st(s.begin(),s.end());
        
        for(auto it: s){
            v1[it-'a']++;
        }
        
        for(auto it: t){
            if(st.find(it) == st.end())
                return 0;
            
            v2[it-'a']++;
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return v1 == v2;
    }
};