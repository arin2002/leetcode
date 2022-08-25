class Solution {
public:
    
//     int helper(int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
//         if(n==0 && m == 0){
//             if(obstacleGrid[0][0] == 1)
//                 return 0;
            
//             return 1;
//         }        
//         if(n<0 || m<0)
//             return 0;
        
//         if(dp[n][m] != -1)
//             return dp[n][m];
        
//         int l = 0, r = 0;
        
        
//         if(obstacleGrid[n][m] == 0){
//             l = helper(n-1,m,obstacleGrid,dp);
//             r = helper(n,m-1,obstacleGrid,dp);
//         }
        
//         return dp[n][m] = l+r;
//     }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // return helper(n-1,m-1,obstacleGrid,dp);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 && j == 0){
                    if(obstacleGrid[i][j] == 1)
                        return 0;
                    else
                        dp[i][j] = 1;
                    
                    continue;
                }
                
                int l = 0, r = 0;
                
                if(i>0 && obstacleGrid[i][j] == 0)
                    l = dp[i-1][j];
                
                if(j>0 && obstacleGrid[i][j] == 0)
                    r = dp[i][j-1];
                
                dp[i][j] = l+r;
            }
        }
        
        return dp[n-1][m-1];
    }
};