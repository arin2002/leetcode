class Solution {
public:
    string sortVowels(string s) {
        string t;
        unordered_set<char> st{'a','e','i','o','u','A','E','I','O','U'};
        unordered_map<char,int> ump;
        for(auto &it: s){
            if(st.find(it) != st.end()){
                ump[it]++;
            }
        }
        
        int j = 0;
        string sorted = "AEIOUaeiou";
        
        
        for(auto &it: s){
            if(st.find(it) != st.end()){
                while(ump[sorted[j]] == 0){
                    j++;
                }
                
                it = sorted[j];
                ump[sorted[j]]--; 
            }
        }
        
        return s;
    }
};