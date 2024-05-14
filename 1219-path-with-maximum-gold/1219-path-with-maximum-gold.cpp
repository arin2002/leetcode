class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> drs{-1,0,1,0,-1};
        
        function<int(int,int)> solve = [&](int i, int j){
            if(i == n || j == m || i < 0 || j < 0)
                return 0;
            
            if(!grid[i][j])
                return 0;
            
            int temp = grid[i][j], ans = 0;
            grid[i][j] = 0;
            
            for(int k = 0; k<4; k++){
                int nx = i+drs[k], ny = j+drs[k+1];
                
                ans = max(ans,temp+solve(nx,ny));
            }
            
            grid[i][j] = temp;
            return ans;
        };
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = max(ans,solve(i,j));
            }
        }
        
        return ans;
    }
};