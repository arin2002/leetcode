class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size(), dist = -1;
        
        vector<vector<int>> vis(n,vector<int>(n));
        int drs[] = {-1,0,1,0,-1};
        queue<pair<int,int>> q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        if(q.size() == n*n)
            return -1;
        
        while(!q.empty()){
            int m = q.size();
            for(int i = 0; i<m; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for(int j = 0; j<4; j++){
                    int nrow = row + drs[j];
                    int ncol = col + drs[j+1];
                    if(nrow>=0 && ncol >= 0 && nrow<n && ncol<n && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
            
            dist++;
        }
        
        return dist;
    }
};