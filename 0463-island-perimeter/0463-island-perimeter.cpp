class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vector<int> drs{-1,0,1,0,-1};
        
        function<bool(int,int)> check = [&](int i, int j){
            if(i<0 || i == n || j<0 || j == m || grid[i][j] == 0)
                return true;

            return false;
        };
        
        function<int(int,int)> solve = [&](int i, int j){
            if(i<0 || i == n || j<0 || j == m || vis[i][j] || grid[i][j] == 0){
                return 0;
            }
            
            vis[i][j] = 1;
            int ans = 0;
            
            for(int k = 0; k<4; k++){
                int nx = i+drs[k];
                int ny = j+drs[k+1];
                
                if(check(nx,ny)){
                    ans += 1;
                }
            }
            
            for(int k = 0; k<4; k++){
                int nx = i+drs[k];
                int ny = j+drs[k+1];
                
                ans += solve(nx,ny);
            }
            
            return ans;
        };
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]){
                    return solve(i,j);
                }
            }
        }
        
        return 0;
    }
};