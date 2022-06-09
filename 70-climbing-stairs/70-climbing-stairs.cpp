class Solution {
public:
    int ans = 0;
    int steps(int n, vector<int> &dp)
    {
        if(n<0)
            return 0;
        if(n==0 || n==1)
            return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = steps(n-1,dp)+steps(n-2,dp);
        
        //return l+r;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return steps(n,dp);
    }
};