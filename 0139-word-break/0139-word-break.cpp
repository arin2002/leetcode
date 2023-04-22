class Solution {
public:
    
    vector<int> dp;
    
    bool solve(int i, unordered_set<string> &st, string &s){
        if(i == s.size())
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        string word = "";
        for(int j = i; j<s.size(); j++){
            word += s[j];
            
            // har jagye se partiton ho raha isme
            // ek side se karoge to saari possiblity muskil h aana
            // size dekh leta dp lagini the
            if(st.find(word) != st.end()){
                if(solve(j+1,st,s)){
                    return dp[i] = 1;
                }
            }
        }
        
        return dp[i] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.size();
        
        dp.resize(n,-1);
        for(auto &it: wordDict)
            st.insert(it);
        
        return solve(0,st,s);
    }
};