class Solution {
public:
    
    bool check(int i, int j, vector<vector<int>>& grid){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0)
            return 1;
        
        if(grid[i][j] == -1 || grid[i][j] == -2)
            return 1;
        
        return 0;
    }
    
    int f(int i, int j, int count, vector<vector<int>>&grid, vector<vector<vector<int>>> &dp){
        if(check(i,j,grid))
            return 0;
        
        if(grid[i][j] == 2){
            if(count != 0)
                return 0;
            
            return 1;
        }
        
        if(dp[i][j][count] != -1)
            return dp[i][j][count];
        
        grid[i][j] = -2;
        count--;
        int l = f(i+1,j,count,grid,dp);
        int r = f(i,j+1,count,grid,dp);
        int z = f(i,j-1,count,grid,dp);
        int p = f(i-1,j,count,grid,dp);
        
        grid[i][j] = 0;
        return dp[i][j][count] = l+r+z+p;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int p = 0, q = 0, count = 1;
        
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 0)
                    count++;
                if(grid[i][j] == 1){
                    p = i;
                    q = j;
                }
            }
        }
        
        vector<vector<vector<int> > > dp(grid.size(), vector<vector<int> >(grid[0].size(), vector<int>(count+1,-1)));
        return f(p,q,count,grid,dp);
    }
};