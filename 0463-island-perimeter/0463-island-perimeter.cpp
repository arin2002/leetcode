class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vector<int> drs{-1,0,1,0,-1};
        int ans = 0;
        
        function<bool(int,int)> check = [&](int i, int j){
            if(i<0 || i == n || j<0 || j == m || grid[i][j] == 0)
                return true;

            return false;
        };
       
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!grid[i][j])
                    continue;
                
                for(int k = 0; k<4; k++){
                    int nx = i + drs[k];
                    int ny = j + drs[k+1];
                    
                    if(check(nx,ny)){
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};