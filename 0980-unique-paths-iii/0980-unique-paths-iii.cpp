class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        int x = 0, y = 0;
        vector<int> drs{-1,0,1,0,-1};
        
        function<int(int,int,int)>solve = [&](int r, int c, int count){
            if(r<0 || c<0 || r == n || c == m || grid[r][c] == -1)
                return 0;
            
            // cout<<grid[r][c]<<" "<<count<<endl;
            if(grid[r][c] == 2 && count == -1){
                return 1;
            }
            
            int l = 0, t = 0;
            t = grid[r][c];
            grid[r][c] = -1;
            
            for(int i = 0; i<4; i++){
                int nx = r+drs[i];
                int ny = c+drs[i+1];
                l += solve(nx,ny,count-1);
            }
            
            grid[r][c] = t;
            return l;
        };
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    x = i; y = j;
                }
                else if(grid[i][j] == 0)
                    count++;
            }
        }
        
        return solve(x,y,count);
    }
};