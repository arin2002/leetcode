class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> drs = {{1,-1},{1,0},{1,1}};
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX)); 
        
        function<int(int,int)> solve = [&](int i, int j){
            if(i == n || j == m || i < 0 || j < 0)
                return (int)1e6;
            
            if(i == n-1)
                return matrix[i][j];
            
            if(dp[i][j] != INT_MAX)
                return dp[i][j];
            
            int ans = INT_MAX;
            for(auto &it: drs){
                int nx = i + it[0], ny = j + it[1];
                ans = min(ans, matrix[i][j] + solve(nx, ny));
            }
            
            return  dp[i][j] = ans;
        };
        
        int ans = INT_MAX;
        for(int j = 0; j < m; j++){
            ans = min(ans, solve(0, j));
        }
        
        return ans;
    }
};
