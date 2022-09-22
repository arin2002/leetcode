class Solution {
public:
    
    int f(int i, int j, vector<int> &nums, int n, vector<vector<int>> &dp){
        if(i >= n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // if(j == 2)
        //     return dp[i][j] = f(i+1,1,nums,n,dp);
        
        else if(j==1){
            return dp[i][j] = max(-nums[i]+f(i+1,0,nums,n,dp), 0+f(i+1,1,nums,n,dp));
        }
        else{
            return dp[i][j] = max(nums[i]+f(i+2,1,nums,n,dp), 0+f(i+1,0,nums,n,dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return f(0,1,prices,n,dp);
    }
};