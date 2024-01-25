class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        function<int(int,int)> solve = [&](int i, int j){
            if(i == n || j == m){
                return 0;
            }
            
            if(dp[i][j] != -1)
                return dp[i][j];
            
            if(text1[i] == text2[j]){
                return dp[i][j] = 1+solve(i+1,j+1);
            }
            
            int l = solve(i+1,j);
            int r = solve(i,j+1);
            
            return dp[i][j] = max(l,r);
        };
        
        return solve(0,0);
    }
};