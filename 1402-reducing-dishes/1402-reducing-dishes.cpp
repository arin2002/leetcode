class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int ind, int time, vector<int> &nums){
        if(ind >= nums.size())
            return 0;
        
        if(dp[ind][time] != -1)
            return dp[ind][time];
        
        int l = nums[ind]*time + solve(ind+1,time+1,nums);
        int r = 0 + solve(ind+1,time,nums);
        
        return dp[ind][time] = max(l,r);
    }
    
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        dp.resize(n,vector<int>(n+1,-1));
        return solve(0,1,nums);
    }
};