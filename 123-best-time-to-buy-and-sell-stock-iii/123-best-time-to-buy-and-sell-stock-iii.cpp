class Solution {
public:
    
    int f(int i, int j, int k, vector<int> &nums,int n, vector<vector<vector<int>>> &dp){
        if(i==n || k == 0)
            return 0;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        if(j==1){
            int l = -nums[i] + f(i+1,0,k,nums,n,dp);
            int r = 0 + f(i+1,1,k,nums,n,dp);
            
            return dp[i][j][k] = max(l,r);
        }
        else{
            int a = nums[i] + f(i+1,1,k-1,nums,n,dp);
            int b = 0 + f(i+1,0,k,nums,n,dp);
            
            return dp[i][j][k] = max(a,b);
        }
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n,vector(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp);
    }
};