class Solution {
public:
    
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = 1 + solve(i-1,j-1,s,t,dp);
        
        
        return dp[i][j] = max(solve(i,j-1,s,t,dp),solve(i-1,j,s,t,dp));
    }
    
    int longestCommonSubsequence(string &s, string &t) {
        int n = s.size()-1, m = t.size()-1;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,t,dp);
    }
};