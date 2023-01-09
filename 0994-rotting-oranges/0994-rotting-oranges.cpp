class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = -1, fresh = 0;
        
        queue<pair<int,int>> q;        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        int drow[] = {-1,0,1,0,-1};
        
        while(!q.empty()){
            int s = q.size();
            
            while(s--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
            
                for(int i = 0; i<4; i++){
                    int nr = x + drow[i];
                    int nc = y + drow[i+1];
                
                    if(nr>=0 && nr<n && nc>=0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        if(fresh > 0)
            return -1;
        
        if(ans == -1)
            return 0;
        
        return ans;
    }
};