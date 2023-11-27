class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>>pad(10);
        int mod=1e9+7;
        // Building the pad array
        pad[0]={4,6}; pad[1]={6,8}; pad[2]={7,9}; pad[3]={4,8}; pad[4]={0,3,9}; pad[6]={0,1,7};
        pad[7]={2,6}; pad[8]={1,3}; pad[9]={2,4};
        vector<vector<int>>dp(n,vector<int>(10));
        // Initializing the first row
        for(int i=0;i<10;i++)
            dp[0][i]=1;

        for(int i=1;i<n;i++){
            for(auto j=0;j<10;j++){
                // Checking for possible paths and accumulating 
                // them for digit j
                for(auto &x:pad[j])
                    dp[i][j]=(dp[i][j]+dp[i-1][x])%mod;
            }
        }
        int ans=0;
        for(int i=0;i<10;i++){
            ans=(ans+dp[n-1][i])%mod;
        }
        return ans;
    }
};
// 