class Solution {
public:
    int n,m;
    vector<int> drs = {-1,0,1,0,-1};
    
    void dfs(int i, int j, vector<vector<int>>& grid, int &ones){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0){
            return;
        }
        if(grid[i][j])
            ones++;
        
        grid[i][j] = 0;
        for(int k = 0; k<4; k++){
            dfs(i+drs[k],j+drs[k+1],grid,ones);
        }        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]){
                    int temp = 0;
                    dfs(i,j,grid,temp);
                    ans = max(ans,temp);
                }
            }
        }
        
        return ans;
    }
};