class Solution {
public:
    int n,m;
    vector<int> drs = {-1,0,1,0,-1};
    
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || !grid[i][j]){
            return;
        }
        
        grid[i][j] = 0;
        for(int k = 0; k<4; k++){
            dfs(i+drs[k],j+drs[k+1],grid);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        
        for(int i = 0; i<n; i++){
            if(grid[i][0]){
                dfs(i,0,grid);
            } 
            
            if(grid[i][m-1])
                dfs(i,m-1,grid);
        }
        
        for(int i = 0; i<m; i++){
            if(grid[0][i]){
                dfs(0,i,grid);
            }
            
            if(grid[n-1][i]){
                dfs(n-1,i,grid);
            }
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j])
                    ans++;
            }
        }
        
        return ans;
    }
};