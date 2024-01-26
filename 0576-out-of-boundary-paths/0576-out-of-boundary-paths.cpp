class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> visited(m,vector<int>(n));
        vector<int> drs{-1,0,1,0,-1};
        int mod = 1e9+7;
        int dp [m][n][maxMove + 1];
        memset(dp, -1, sizeof(dp));
        
        function<int(int,int,int)> solve = [&](int i, int j, int c){
            if(i == m || j == n || i == -1 || j == -1)
                return 1;
            
            if(i > m || j>n || i < -1 || j < -1)
                return 0;
            
            if(c == 0){
                if(i == m || j == n || i == -1 || j == -1)
                    return 1;
                
                return 0;
            }
            
            if(dp[i][j][c] != -1)
                return dp[i][j][c];
            
            int ans = 0;
            for(int k = 0; k<4; k++){
                int nx = i+drs[k];
                int ny = j+drs[k+1];
                
                ans = (ans%mod + solve(nx,ny,c-1)%mod)%mod;
            }
            
            return dp[i][j][c]= ans%mod;
        };
        
        return solve(startRow,startColumn,maxMove)%mod;
    }
};