class Solution {
public:
    
    
    int helper(int i, int j1, int j2, int n, int m, vector<vector<int>>&t,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1>m || j2<0 || j2>m)
            return -1e9;
        
        if(i==n){
            if(j1==j2)
                return t[i][j1];
            
            return t[i][j1] + t[i][j2];
        }
        
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        int maxi = -1e9;
        for(int d1 = -1; d1<=1; d1++){
            for(int d2 = -1; d2<=1; d2++){
                if(j1==j2)
                    maxi = max(maxi, helper(i+1,j1+d1,j2+d2,n,m,t,dp));
                else
                    maxi = max(maxi, t[i][j1]+t[i][j2] +helper(i+1,j1+d1,j2+d2,n,m,t,dp));
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j]==0)
                    count++;
            }
        }
        if(count == n*m)
            return 0;
        
        return helper(0,0,m-1,n-1,m-1,grid,dp);
    }
};