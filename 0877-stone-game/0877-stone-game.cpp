class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int i, int j, vector<int>& nums){
        if(i == j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int l = nums[i] - solve(i+1,j,nums);
        int r = nums[j] - solve(i,j-1,nums);
        
        return dp[i][j] = max(l,r);
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,piles) > 0;
    }
};