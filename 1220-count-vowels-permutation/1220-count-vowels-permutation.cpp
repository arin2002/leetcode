class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n, vector<long>(5, 0));
        int MOD = 1e9 + 7;
        
        for(int j = 0; j < 5; j++)
            dp[0][j] = 1;
        
        for(int i = 1; i < n; i++){
            dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) %MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD;
            dp[i][3] = dp[i-1][2] % MOD;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        }
    
    int ans = 0;
    for(int j = 0; j < 5; j++)
        ans = (ans + dp[n-1][j]) % MOD;
    
    return ans;
    }
};
