class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        unordered_set<string> st(d.begin(),d.end());
        int n = s.size();
        vector<int> dp(n+1,-1);
        
        function<int(int)>solve = [&](int ind){
            if(ind == n)
                return 0;
            
            if(dp[ind] != -1)
                return dp[ind];
            
            string  t;
            int l = INT_MAX;
            for(int i = ind; i<n; i++){
                t += s[i];
                
                if(st.find(t) != st.end()){
                    l = min(l,solve(i+1));
                }
                
                l = min(l,i-ind+1+solve(i+1));
            }
            
            return dp[ind] = l;
        };
        
        
        return solve(0);
    }
};