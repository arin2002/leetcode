class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        unordered_set<string> st(w.begin(),w.end());
        int n = s.size();
        vector<int> dp(n,-1);
        function<int(int)>solve = [&](int ind){
            
            if(ind == n)
                return 1;
            
            if(dp[ind] != -1)
                return dp[ind];
            
            string t;
            for(int i = ind; i<n; i++){
                t += s[i];
                
                if(st.find(t) != st.end()){
                    if(solve(i+1)){
                        return dp[ind] = 1;
                    }
                }
            }
            
            return dp[ind] = 0;
        };
        
        return solve(0);
    }
};