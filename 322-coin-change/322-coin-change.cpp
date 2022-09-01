class Solution {
public:
    
    
    int f(int n, int k, vector<int>& t,vector<vector<int>> &dp){
        
        if(n<0){
            if(k == 0)
                return 0;
            return 1e9;
        }
        
        if(n == 0){
            if(k%t[n] == 0)
                return k/t[n];
            
            return 1e9;
        }
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        int l = INT_MAX;
        if(t[n]<=k)
            l = 1 + f(n, k-t[n],t,dp);
        
        int r = f(n-1, k, t, dp);
        
        return dp[n][k] = min(l,r);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        if(amount == 0)
            return 0;
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        
        if(ans == 1e9) return -1;
        return ans;
        
    }
};