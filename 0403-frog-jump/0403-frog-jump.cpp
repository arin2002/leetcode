class Solution {
public:
    bool canCross(vector<int>& nums) {
        int n = nums.size();
        
        if(nums[1] != 1)
            return 0;
        
        unordered_map<int, int> ump;
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Initializing dp array

        for (int i = 0; i < n; i++) {
            ump[nums[i]] = i;
        }

        function<int(int, int)> solve = [&](int ind, int k) {
            if (ind == n - 1)
                return 1;

            if (dp[ind][k] != -1) {
                return dp[ind][k];
            }

            auto a = ump.find(nums[ind] + k);
            auto b = ump.find(nums[ind] + k - 1);
            auto c = ump.find(nums[ind] + k + 1);

            int l = 0;
            if (a != ump.end() && a->second > ind) {
                l |= solve(a->second, k);
            }

            if (b != ump.end() && b->second > ind) {
                l |= solve(b->second, k - 1);
            }

            if (c != ump.end() && c->second > ind) {
                l |= solve(c->second, k + 1);
            }

            return dp[ind][k] = l;
        };

        return solve(1, 1);
    }
};
