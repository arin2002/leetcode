class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(int i, int j, string &s, string &t){
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = 1+solve(i-1,j-1,s,t);
        }
        
        return dp[i][j] = max(solve(i-1,j,s,t),solve(i,j-1,s,t));
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        
        dp.resize(n,vector<int>(n,-1));
        return solve(n-1,n-1,s,t);
    }
};