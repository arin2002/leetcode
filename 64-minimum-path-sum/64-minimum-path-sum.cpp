class Solution {
public:
    
    int path(int n, int m,vector<vector<int>>& grid,vector<vector<int>>&dp){
        
        if(n == 0 && m == 0){
            return  grid[0][0];
        }
        if(n<0 || m<0)  return 1000000;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        int l = grid[n][m] + path(n-1,m,grid,dp);
        int r = grid[n][m] + path(n,m-1,grid,dp);
        
        return dp[n][m] = min(l,r);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m =  grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return path(n-1,m-1,grid,dp);
    }
};