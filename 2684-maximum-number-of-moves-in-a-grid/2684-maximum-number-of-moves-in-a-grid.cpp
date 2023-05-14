class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(int i, int j, int prev, vector<vector<int>>& grid){
        if(i<0 || i >= n || j<0 || j>=m || grid[i][j] <= prev)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int l = 1 + solve(i-1,j+1,grid[i][j],grid);
        int r = 1 + solve(i,j+1,grid[i][j],grid);
        int z = 1 + solve(i+1,j+1,grid[i][j],grid);
        
        return dp[i][j] = max({l,r,z});
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans,solve(i,0,-1,grid));
        }
        
        return ans-1;
    }
};