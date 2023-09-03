class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)>solve = [&](int x, int y){
            if(x < 0 || x == n || y <0 || y == m){
                return 0;
            }
            
            if(x == n-1 && y == m-1)
                return 1;
            
            if(dp[x][y] != -1)
                return dp[x][y];
            
            int l = solve(x+1,y);
            int r = solve(x,y+1);
            
            return dp[x][y]= l+r;
        };
        
        return solve(0,0);
    }
};