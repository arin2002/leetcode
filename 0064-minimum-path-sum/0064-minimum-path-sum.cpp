class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<vector<int>> &grid){
        int n = grid.size(), m = grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m)
            return 1e7;
        
        if(i == n-1 && j == m-1)
            return grid[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int l = grid[i][j] + dfs(i+1,j,grid);
        int r = grid[i][j] + dfs(i,j+1,grid);
        
        return dp[i][j] = min(l,r);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
        return dfs(0,0,grid);
    }
};