class Solution {
public:
    string sortVowels(string s) {
        string t;
        unordered_set<char> st{'a','e','i','o','u','A','E','I','O','U'};
        
        for(auto &it: s){
            if(st.find(it) != st.end()){
                t += it;
            }
        }
        
        sort(t.begin(),t.end());
        int i = 0;
        
        for(auto &it: s){
            if(st.find(it) != st.end()){
                it = t[i++];
            }
        }
        
        return s;
    }
};