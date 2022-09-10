class Solution {
public:
    
    
    int f(int i, int j, vector<vector<int>> &t, vector<vector<int>> &dp){
        
        if(i<0 || j<0)
            return 10000;
        
        if(i == 0 && j == 0)
            return t[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int l = t[i][j] + f(i-1,j,t,dp);
        int r = t[i][j] + f(i,j-1,t,dp);
        
        return dp[i][j] = min(l,r);
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return f(m-1,n-1,grid,dp);
    }
};