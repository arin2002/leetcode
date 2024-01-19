class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n = matrix.size();
         
       int mini = INT_MAX;
       vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
       for (int i = 0; i < n; i++) {
           mini = min(mini, solve(0, i, matrix, n, dp));
       }
       return mini;
    }

    int solve(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp) {
        if (row == n) return 0; // Change condition to row == n
        if (col < 0 || col >= n) return INT_MAX; // Change col > n-1 to col >= n
        if (dp[row][col] != INT_MAX) return dp[row][col]; 
      
        dp[row][col] = matrix[row][col] + min(
            solve(row + 1, col, matrix, n, dp),
            min(solve(row + 1, col + 1, matrix, n, dp), solve(row + 1, col - 1, matrix, n, dp))
        );

        return dp[row][col];
    }
};
