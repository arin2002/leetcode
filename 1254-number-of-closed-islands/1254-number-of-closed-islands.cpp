class Solution {
public:
    
    vector<int> drs = {-1,0,1,0,-1};
    
    bool bfs(int i, int j, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        
        int n = grid.size(), m = grid[0].size();
        bool isClosed = true;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            grid[x][y] = 1;
            
            for(int k = 0; k<4; k++){
                int nx = x + drs[k];
                int ny = y + drs[k+1];
                
                // boundary point hua to return false kyuki
                // 4 side se water nahi h
                // return false na karna direct kyuki hame sare island chaiye
                // usse connected
                if(nx < 0 || nx>= n || ny < 0 || ny>=m){
                    isClosed = false;
                }
                else if(grid[nx][ny] == 0){
                    q.push({nx,ny});
                }
            }
            
        }
        return isClosed;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0 && bfs(i,j,grid)){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};