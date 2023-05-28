class Solution {
public:
    unordered_set<string> st;
    int n;
    vector<int> dp;
    int solve(int ind, string &s){
        if(ind >= n){
            return 0;
        }
        
        if(dp[ind] != -1)
            return dp[ind];
        
        string t = "";
        
        int ans = 1e6;
        for(int i = ind; i<n; i++){
            t += s[i];
            if(st.find(t) != st.end())
                ans = min(ans,solve(i+1,s));
            
            ans = min(ans,(int)t.length()+solve(i+1,s));
        }
        
        return dp[ind] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dict) {
        for(auto &it: dict)
            st.insert(it);
        
        n = s.size();
        dp.resize(n,-1);
        return solve(0,s);
    }
};