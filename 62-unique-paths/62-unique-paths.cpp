class Solution {
public:
    
    int helper(int i, int j,vector<vector<int>> &dp){
        if(i == 0 && j==0)
            return 1;
        
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int l = helper(i-1,j,dp);
        int r = helper(i,j-1,dp);
        
        return dp[i][j] = l+r;
    }
    
    int uniquePaths(int i ,int j) {
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return helper(i-1,j-1,dp);
    }
};