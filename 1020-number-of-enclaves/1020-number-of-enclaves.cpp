class Solution {
public:
    
    int drs[5] = {-1,0,1,0,-1};
    
    
    void dfs(int i, int j, vector<vector<int>>& vis,vector<vector<int>>& grid){
        if(i<0 || i >= grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0 || vis[i][j])
            return;
        
        vis[i][j] = 1;
        for(int k = 0; k<4; k++){
            dfs(i+drs[k],j+drs[k+1],vis,grid);
        }
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(),ans = 0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0; i<m; i++){
            if(grid[0][i] == 1 && !vis[0][i])
                dfs(0,i,vis,grid);
            
            if(grid[n-1][i] == 1 && !vis[n-1][i])
                dfs(n-1,i,vis,grid);
        }
        
        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1 && !vis[i][0])
                dfs(i,0,vis,grid);
            
            if(grid[i][m-1] == 1 && !vis[i][m-1])
                dfs(i,m-1,vis,grid);
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1)
                    ans++;
            }
        }
        
        return ans;
    }
};