class Solution {
public:
    
    
    int f(int i, int k, vector<int>& t, vector<vector<int>> &dp){
        if(i < 0){
            if(k == 0)
                return 1;
            
            return 0;
        }
        
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int l = 0;
        
        if(t[i] <= k)
            l = f(i,k-t[i],t,dp);
        
        int r = f(i-1,k,t,dp);
        return dp[i][k] = l+r;
    }
    
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};