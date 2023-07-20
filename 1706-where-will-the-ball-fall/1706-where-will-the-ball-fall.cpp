class Solution {
public:
    vector<int> ans;
    int m,n;
    
    bool check(int row, int col){
        if(row < 0 || col <0 || row>=n || col >= m)
            return false;
        
        return true;
    }
    
    int dfs(int row, int col, vector<vector<int>>& grid){
        if(row == n){
            // cout<<row<<" ";
            return col;
        }
        
        if(check(row,col)){
            if(grid[row][col] == 1){
                if(check(row,col+1) && grid[row][col+1] == 1){
                    return dfs(row+1,col+1,grid);
                }
            }
            else{
                if(check(row,col-1) && grid[row][col-1] == -1){
                    return dfs(row+1,col-1,grid);
                }
            }
        }
        
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        
        for(int i = 0; i<m; i++){
            ans.push_back(dfs(0,i,grid));
        }
        return ans;
    }
};