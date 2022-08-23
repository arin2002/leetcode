class Solution {
public:
    
    int helper(vector<int> &nums, int i, vector<int> &dp)
    {
        if(i==0) return nums[i];
        if(i<0)  return 0;
        
        if(dp[i] != -1)
            return dp[i];
        int pick = nums[i] + helper(nums,i-2,dp);
        
        int not_pick = 0 + helper(nums,i-1,dp);
        
        return dp[i] = max(pick,not_pick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        vector<int> dp(n+1,-1);
        int a = helper(nums,n-2,dp);
        
        nums[0] = 0;
        vector<int> dp1(n+1,-1);
        int b = helper(nums,n-1,dp1);
        
        return max(a,b);
    }
};