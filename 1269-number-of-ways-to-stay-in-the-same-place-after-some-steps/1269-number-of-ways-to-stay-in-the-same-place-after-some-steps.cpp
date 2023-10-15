class Solution {
public:
    int numWays(int steps, int n) {
        int mod = 1e9 + 7;
        int m = min(steps, n);
        vector<vector<long long>> dp(501, vector<long long>(steps + 1, -1));

        function<long long(int, int)> solve = [&](int ind, int s) -> long long {
            if (ind < 0 || ind >= m) {
                return 0;
            }

            if (s == 0) {
                if (ind == 0) {
                    return 1;
                }
                return 0;
            }

            if (dp[ind][s] != -1) {
                return dp[ind][s] % mod;
            }

            long long l = solve(ind + 1, s - 1) % mod;
            long long r = solve(ind - 1, s - 1) % mod;
            long long z = solve(ind, s - 1) % mod;

            return dp[ind][s] = (l % mod + r % mod + z % mod) % mod;
        };

        return solve(0, steps);
    }
};
