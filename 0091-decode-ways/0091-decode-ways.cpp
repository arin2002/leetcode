class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        
        function<int(int)> solve = [&](int ind){
            if(ind == s.size())
                return dp[ind] = 1;
            
            if(dp[ind] != -1)
                return dp[ind];
            
            string t; int l = 0;
            for(int i = ind; i<n; i++){
                t += s[i];
                
                if(stoi(t) > 26 || t == "0"){
                    break;
                }
                
                l += solve(i+1);
            }
            
            return dp[ind] = l;
        };
        
        
        return solve(0);
    }
};