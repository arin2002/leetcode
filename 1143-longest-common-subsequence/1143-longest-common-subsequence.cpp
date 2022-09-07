class Solution {
public:
    
    
    int maxi = 0;
    
    int f(int n, int m, string &a, string &b, vector<vector<int>> &dp){
        if(n < 0 || m < 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        // int l = 0,r = 0, z = 0;
        if(a[n] == b[m])
            return dp[n][m] = 1 + f(n-1,m-1,a,b,dp);
        
        else
            return dp[n][m] = max(f(n-1,m,a,b,dp),f(n,m-1,a,b,dp));
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};