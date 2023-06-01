class Solution {
public:
    int n;
    vector<int> drs = {-1,0,1,0,-1,-1,1,1,-1};
    
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j] == 1)
            return 0;
        
        return 1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = INT_MAX;
        
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        grid[0][0] = 1;
        
        while(!q.empty()){
            int x = q.front().second.first;
            int y = q.front().second.second;
            int temp = q.front().first;
            q.pop();
            
            if(x == n-1 && y == n-1)
                return temp;
            
            for(int k = 0; k<8; k++){
                int nx = x+drs[k];
                int ny = y+drs[k+1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny] == 0){
                    q.push({temp+1,{nx,ny}});
                    grid[nx][ny] = 1;
                }
            }
            
//             if(solve(x+1,y+1,grid)){
//                 q.push({temp+1,{x+1,y+1}});
//                 grid[x+1][y+1] = 1;
//             }
            
//             if(solve(x-1,y-1,grid)){
//                 q.push({temp+1,{x-1,y-1}});
//                 grid[x-1][y-1] = 1;
//             }
            
            
//             if(solve(x-1,y+1,grid)){
//                 q.push({temp+1,{x-1,y+1}});
//                 grid[x-1][y+1] = 1;
//             }
            
//             if(solve(x+1,y-1,grid)){
//                 q.push({temp+1,{x+1,y-1}});
//                 grid[x+1][y-1] = 1;
//             }
        }
        
        // return ans == INT_MAX ? -1: ans;
        return -1;
    }
};