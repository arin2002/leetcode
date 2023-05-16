class Solution {
public:
    int mod = 1e9+7;
    int Zero, One;
    vector<long> dp;
    
    long solve(long n){
        if(n < 0)
            return 0;
        
        if(n == 0)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int l = solve(n-Zero)%mod;
        int r = solve(n-One)%mod;
        
        return dp[n] = (l%mod+r%mod)%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        Zero = zero; One = one;
        
        long ans = 0;
        dp.resize(high+1,-1);
        for(int i = low; i<=high; i++){
            ans = (ans%mod + solve(i)%mod)%mod;
        }
        
        return ans;
    }
};