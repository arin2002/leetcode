class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0, n = board.size(), m = board[0].size();
        vector<int> drs {-1,0,1,0,-1};
        
        function<void(int,int)> solve = [&](int i, int j){
            if(i<0 || j<0 || i == n || j == m || board[i][j] == '.')
                return;
            
            board[i][j] = '.';
            
            for(int k = 0; k<4; k++){
                int nx = i+drs[k], ny = j+drs[k+1];
                
                solve(nx,ny);
            }
        };
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == '.')
                    continue;
                
                ans++;
                solve(i,j);
            }
        }
        
        return ans;
    }
};