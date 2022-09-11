class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length(), m = t.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
       return (n-dp[n][m]) + (m-dp[n][m]);
    }
};