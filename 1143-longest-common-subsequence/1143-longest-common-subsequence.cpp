class Solution {
public:
    
    int f(int n, int m, string &a, string &b, vector<vector<int>> &dp){
        if(n < 0 || m < 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        int l = -1e9;
        if(a[n] == b[m])
             l = 1 + f(n-1,m-1,a,b,dp);
        
        int r = 0 + f(n-1,m,a,b,dp);
        int z = 0 + f(n,m-1,a,b,dp);
        
        return dp[n][m] = max(l,max(r,z));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};