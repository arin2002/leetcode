class Solution {
public:
    
    bool check(int i, int j, vector<vector<int>>&vis, vector<vector<char>>& board){
        if(i<0 || i >= board.size() || j < 0 || j>=board[0].size() || vis[i][j] == 1)
            return true;
        
        return false;
    }
    
    
    void dfs(int i, int j,vector<vector<int>> &vis,vector<vector<char>>& board){
        if(check(i,j,vis,board))
            return;
        
        vis[i][j] = 1;
        int drs[] = {-1,0,1,0,-1};
        
        for(int k = 0; k<4; k++){
            dfs(i+drs[k],j+drs[k+1],vis,board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'X')
                    vis[i][j] = 1;
            }
        }
        
        for(int j = 0; j<m; j++){
            if(board[0][j] == 'O'){
                if(!vis[0][j]){
                    dfs(0,j,vis,board);
                }
            }
            
            if(board[n-1][j] == 'O'){
                if(!vis[n-1][j]){
                    dfs(n-1,j,vis,board);
                }
            }
        }
        
        
        for(int j = 0; j<n; j++){
            if(board[j][0] == 'O'){
                if(!vis[j][0]){
                    dfs(j,0,vis,board);
                }
            }
            
            if(board[j][m-1] == 'O'){
                if(!vis[j][m-1]){
                    dfs(j,m-1,vis,board);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }  
    }
};