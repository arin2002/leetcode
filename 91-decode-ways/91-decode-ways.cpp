class Solution {
public:
    
    int f(int i, string &s, vector<int> &dp){
        
        if(s[0] == '0')
            return 0;
        
        if(i <= 1)
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        int count = 0;
        if(s[i-1] != '0')
            count = f(i-1,s,dp);
        
        if(s[i - 2] == '1'|| (s[i - 2] == '2' && s[i-1] < '7'))
            count  += f(i-2,s,dp);
        
        return dp[i] = count;
    }
    
    
    int numDecodings(string s) {
        int n = s.length();
        
        vector<int> dp(n+1,-1);
        return f(n,s,dp);
    }
};