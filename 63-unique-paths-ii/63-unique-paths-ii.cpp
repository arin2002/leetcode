class Solution {
public:
    
    int helper(int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(n==0 && m == 0){
            if(obstacleGrid[0][0] == 1)
                return 0;
            
            return 1;
        }        
        if(n<0 || m<0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        int l = 0, r = 0;
        
        
        if(obstacleGrid[n][m] == 0){
            l = helper(n-1,m,obstacleGrid,dp);
            r = helper(n,m-1,obstacleGrid,dp);
        }
        
        return dp[n][m] = l+r;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,obstacleGrid,dp);
    }
};