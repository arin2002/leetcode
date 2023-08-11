class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        function<int(int,int)>solve = [&](int ind, int amount){
            if(amount < 0)
                return 0;
            
            if(amount == 0)
                return 1;
            
            if(ind == n)
                return 0;
            
            if(dp[ind][amount] != -1)
                return dp[ind][amount];
            
            
            int l = solve(ind,amount-coins[ind]);
            int r = solve(ind+1,amount);
            
            return dp[ind][amount]= l+r;
        };
        
        return solve(0,amount);
    }
};