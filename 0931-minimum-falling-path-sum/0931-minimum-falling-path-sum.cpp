class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=mat.size() || j>= mat[0].size())
            return 1e6;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == 0){
            return dp[i][j] = mat[0][j];
        }
        
        int l = mat[i][j] + solve(i-1,j-1,mat,dp);
        int r = mat[i][j] + solve(i-1,j,mat,dp);
        int x = mat[i][j] + solve(i-1,j+1,mat,dp);
        
        return dp[i][j] = min(l,min(r,x));
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i = 0; i<m; i++){
            ans = min(ans,solve(n-1,i,matrix,dp));
        }
        
        return ans;
    }
};