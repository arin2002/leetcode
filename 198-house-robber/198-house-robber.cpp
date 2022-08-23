class Solution {
public:
    
    int helper(vector<int> nums, int i, vector<int> &dp)
    {
        if(i == 0)  return nums[i];
        if(i<0)     return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int pick = nums[i]+ helper(nums,i-2,dp);  
        
//         if(i>1)
        
//         pick += helper(nums,i-2,dp);
        
        int not_pick = 0 + helper(nums,i-1,dp);
        
        return dp[i] = max(pick,not_pick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n+1,-1);
        return helper(nums,n-1,dp);
    }
};