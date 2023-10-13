class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        function<int(int)>solve = [&](int ind){
            if(ind >= n)
                return 0;
            
            if(dp[ind] != -1)
                return dp[ind];
            
            int l = nums[ind]+solve(ind+1);
            int r = nums[ind]+solve(ind+2);
            
            return dp[ind] = min(l,r);
        };
        
        
        return min(solve(0),solve(1));
    }
};