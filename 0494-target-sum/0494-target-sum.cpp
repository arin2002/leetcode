class Solution {
public:
    
    map<pair<int,int>,int>dp;
    
    int f (int i,int s,vector<int> nums){
        if(i < 0 ){
            if(s == 0)
                return 1;
            
            return 0;
        }
        
        if(dp.find({i,s}) != dp.end())
            return dp[{i,s}];
        
        int l = f(i-1,s+nums[i],nums);
        int r = f(i-1,s-nums[i],nums);
        
        return dp[{i,s}] = l+r;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // since taget can be negative here we used map;
        vector<vector<int>> dp(n+1,vector<int>(1,-1));
        return f(n-1,target,nums);
        
    }
};