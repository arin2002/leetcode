class Solution {
public:
    
//     int helper(int i, int j, int n,vector<vector<int>>& t, vector<vector<int>>&dp)
//     {
//         if(i == n)
//             return t[i][j];
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         int l = t[i][j] + helper(i+1,j,n,t,dp);
//         int r = t[i][j] + helper(i+1,j+1,n,t,dp);
        
//         return dp[i][j] = min(l,r);
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        // return helper(0,0,n-1,triangle,dp);
        
        for(int i = 0; i<n; i++)
            dp[n-1][i] = triangle[n-1][i];
        
        for(int i = n-1; i>=0; i--){
            for(int j = i; j>=0; j--){
                
                if(i==n-1){
                    // dp[i][j] == triangle[i][j];
                    continue;
                }
                
                int l = INT_MAX, r = INT_MAX;
                
                l = triangle[i][j]+dp[i+1][j];
                r = triangle[i][j]+dp[i+1][j+1];
                
                dp[i][j] = min(l,r);
            }
        }
        
        return dp[0][0];
    }
};