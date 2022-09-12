class Solution {
public:
    
    
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i == 0)
            return j;
        
        if(j == 0)
            return i;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i-1] == t[j-1])
            return dp[i][j] = f(i-1,j-1,s,t,dp);
        
        // insert
        int l = 1 + f(i,j-1,s,t,dp);
        // delete
        int r = 1 + f(i-1,j,s,t,dp);
        // replace
        int z = 1 + f(i-1,j-1,s,t,dp);
        
        return dp[i][j] = min(l,min(r,z));
    }
    
    
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // if(n == 0 || m ==0)
        //     return max(n,m);
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,t,dp);
    }
};