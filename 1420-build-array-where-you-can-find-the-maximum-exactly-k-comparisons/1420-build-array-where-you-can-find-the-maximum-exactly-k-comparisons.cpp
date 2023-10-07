class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][51][101];
    int solve(int n, int m, int k, int last){
        if(k < 0) return 0;
        if(n == 0){
            if(k == 0) return 1;
            else return 0;
        }

        if(dp[n][k][last] != -1) return dp[n][k][last];

        int ans = 0;
        for(int i = 1; i<=m; i++){
            if(i > last) ans = (ans + solve(n-1, m, k-1, i))%mod;
            else ans = (ans + solve(n-1, m, k, last))%mod;
        }

        return dp[n][k][last] =  ans;
    }
    int numOfArrays(int n, int m, int k) {
        // if(k > m) return 0;
        memset(dp, -1, sizeof(dp));

        // vector<vector<vector<int>>> dp(n+2, vector<vector<int>>(k+2, vector<int>(m+2, -1)));

        return solve(n, m, k, 0);
    }
};
