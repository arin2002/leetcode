class Solution {
public:
    
    int solve(int i, vector<int> &nums, vector<int> &dp){
        if(i<0)
            return 0;
        
        if(i == 0)
            return nums[i];
        
        if(dp[i] != -1)
            return dp[i];
        
        int l = nums[i]+ solve(i-2,nums,dp);
        int r = 0 + solve(i-1,nums,dp);
        
        return dp[i] = max(l,r);
    }
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1,-1);
        
        return solve(n-1,nums,dp);
    }
};