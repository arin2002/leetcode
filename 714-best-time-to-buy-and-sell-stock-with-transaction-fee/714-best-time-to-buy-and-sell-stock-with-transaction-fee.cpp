class Solution {
public:
    
    int f(int i, int j, vector<int> &nums, int n, int k, vector<vector<int>> &dp){
        if(i == n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(j){
            int l = -nums[i]-k + f(i+1,0,nums,n,k,dp);
            int r = 0 + f(i+1,1,nums,n,k,dp);
            
            return dp[i][j] = max(l,r);
        }
        
        else{
            int a = nums[i] + f(i+1,1,nums,n,k,dp);
            int b = 0 + f(i+1,0,nums,n,k,dp);
            
            return dp[i][j] = max(a,b);
        }
        
    }   
        
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,fee,dp);
    }
};