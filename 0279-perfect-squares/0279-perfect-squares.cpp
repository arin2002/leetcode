class Solution {
public:
    
    int f(int i, int k, vector<int> &v, vector<vector<int>> &dp){
        if(i<0 || k<0)
            return 1e7;
        
        if(k == 0)
            return 0;
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int l = INT_MAX;
        if(k-v[i] >=0)
            l = 1 + f(i,k-v[i],v,dp);
        
        int r = f(i-1,k,v,dp);
        
        return dp[i][k] = min(l,r);
    }
    
    
    int numSquares(int n) {
        vector<int> v;
        
        for(int i = 1; i*i<=n; i++)
            v.push_back(i*i);
        
        vector<vector<int>> dp(v.size(),vector<int>(n+1,-1));
        
        return f(v.size()-1,n,v,dp);
    }
};