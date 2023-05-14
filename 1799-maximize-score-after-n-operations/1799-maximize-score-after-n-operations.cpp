class Solution {
    static inline int pop_count(int x) { return __builtin_popcount(x); }
public:
    int maxScore(vector<int>& a) {
        int n = int(a.size());
        vector<int> dp(1 << n);
        for (int mask = 1; mask < (1 << n); ++mask) {
            int c = pop_count(mask);
            if (c % 2 == 1) continue;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if ((mask >> i & 1) && (mask >> j & 1)) {
                        dp[mask] = max(dp[mask], (c / 2) * gcd(a[i], a[j]) + dp[mask ^ (1 << i) ^ (1 << j)]);
                    }
                }
            }
        }
        return dp.back();
    }
};
