class Solution
{
    public:
    int dp[35][1002];
    const int mod = 1e9 + 7;
    int solve(int dices, int k, int target)
    { 
        if (dices==0 &&target == 0) return 1;
		
		 
        if (dices == 0 || target<0) return 0;
		
		
        
		if (dp[dices][target] != -1) return dp[dices][target];
        
		int countWays = 0;
        
		for (int faceVal = 1; faceVal <= k; faceVal++)
        {
		
           countWays%=mod;
		   
          countWays+=solve(dices-1,k,target-faceVal)%mod;
        }
        
		return dp[dices][target] = countWays%mod;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target) % mod;
    }
};