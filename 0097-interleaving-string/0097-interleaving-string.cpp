class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), mn = s3.size();

        if(n + m != mn)
            return 0;
        
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(mn+1, -1)));
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        function<int(int,int,int)>solve = [&](int i, int j, int k){
            
            // cout<<i<<" "<<j<<" "<<k<<" "<<endl;
            if(i == n && j == m && k == mn){
                return 1;
            }
            
            if(k == mn)
                return 0;
            
            if(dp[i][j]!= -1)
                return dp[i][j];
            
            bool l = 0,r = 0;
            
            if(s1[i] == s3[k])
                l = solve(i+1,j,k+1);
            
            if(s2[j] == s3[k]){
                r = solve(i,j+1,k+1);
            }
            
            return dp[i][j] = l|r;
        };
        
        return solve(0,0,0);
    }
};