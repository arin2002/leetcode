class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size(), m = land[0].size();
        vector<int> drs{-1,0,1,0,-1};
        
        function<bool(int,int)> check = [&](int i, int j){
            int nx = i, ny = j+1;
            
            if(!(nx<0 || ny<0 || nx == n || ny == m)){
                if(land[nx][ny] == 1 || land[nx][ny] == 2)
                    return false;
            }
            
            nx = i+1, ny = j;
            
            if(!(nx<0 || ny<0 || nx == n || ny == m)){
                if(land[nx][ny] == 1 || land[nx][ny] == 2)
                    return false;
            }
            
            return true;
        };
        
        function<void(int,int)> solve = [&](int i, int j){
            if(i<0 || j<0 || i == n || j == m)
                return;
            
            if(land[i][j] == 0 || land[i][j] == 2)
                return;
            
            land[i][j] = 2;
            
            if(check(i,j)){
                ans.back().push_back(i);
                ans.back().push_back(j);
            }
            
            for(int k = 0; k<4; k++){
                int nx = i+drs[k];
                int ny = j+drs[k+1];
                
                solve(nx,ny);
            }
        };
        
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(land[i][j] == 0 || land[i][j] == 2){
                    continue;
                }
                
                ans.push_back({i,j});
                solve(i,j);
            }
        }
        
        return ans;
    }
};