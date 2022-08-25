class Solution {
public:
    
//     int path(int n, int m,vector<vector<int>>& grid,vector<vector<int>>&dp){
        
//         if(n == 0 && m == 0){
//             return  grid[0][0];
//         }
//         if(n<0 || m<0)  return 1000000;
        
//         if(dp[n][m] != -1)
//             return dp[n][m];
        
//         int l = grid[n][m] + path(n-1,m,grid,dp);
//         int r = grid[n][m] + path(n,m-1,grid,dp);
        
//         return dp[n][m] = min(l,r);
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m =  grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // return path(n-1,m-1,grid,dp);
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[0][0];
                    continue;
                }
                int l = INT_MAX, r = INT_MAX;
                if(i>0)
                 l = grid[i][j] + dp[i-1][j];
                
                if(j>0)
                 r = grid[i][j] + dp[i][j-1];
                
                dp[i][j] = min(l,r);
            }
        }
        
        return dp[n-1][m-1];
    }
};