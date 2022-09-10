class Solution {
public:
    
    int f(int n, int m, string &a, string &b, vector<vector<int>> &dp){
        if(n == 0 || m == 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(a[n-1] == b[m-1])
             return dp[n][m] = 1 + f(n-1,m-1,a,b,dp);
        
        int r = 0 + f(n-1,m,a,b,dp);
        int z = 0 + f(n,m-1,a,b,dp);
        
        return dp[n][m] = max(r,z);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,text1,text2,dp);
    }
};