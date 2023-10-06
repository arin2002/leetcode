class Solution {
public:
    int solve(int i,int sum,vector<int>& nums,vector<vector<int>>& dp){
        if(sum==0){
            return 1;
        }
        if(sum<0||i<0){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int take=nums[i]*solve(i,sum-nums[i],nums,dp);
        int notTake=solve(i-1,sum,nums,dp);
        return dp[i][sum]=max(take,notTake);
    }
    int integerBreak(int n) {
        vector<int> nums;
        for(int i=1;i<n;i++){
            nums.push_back(i);
        }
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums.size()-1,n,nums,dp);
    }
};