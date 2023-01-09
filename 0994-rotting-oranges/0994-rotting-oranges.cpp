class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        queue<pair<pair<int,int>,int>> q;        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2)
                    q.push({{i,j},0});
            }
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            ans = max(ans,t);
            
            for(int i = 0; i<4; i++){
                int nr = x + drow[i];
                int nc = y + dcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans;
    }
};