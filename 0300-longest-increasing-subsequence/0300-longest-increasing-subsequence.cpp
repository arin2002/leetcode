class Solution {
public:
    
    int dp[2505][2505];
    
    int solve(int ind, int prev, vector<int>& nums){
        if(ind >= nums.size())
            return 0;
        
        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1];
        
        int l = 0, r = 0;
        if(prev == -1 || nums[ind] > nums[prev])
            l = 1 + solve(ind+1,ind,nums);
        
        r = solve(ind+1,prev,nums);
        
        return dp[ind][prev+1] = max(l,r);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};