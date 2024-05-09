class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        
        for(int i = 1; i*i<=n; i++){
            nums.push_back(i*i);
        }
                
        int m = nums.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        function<int(int,int)> solve = [&](int ind, int n){
            if(n < 0)
                return (int)1e6;
            
            if(n == 0)
                return 0;
            
            if(ind < 0)
                return (int)1e6;
            
            if(dp[ind][n] != -1)
                return dp[ind][n];
            
            // int cnt = n%nums[ind]
            int take = 1+solve(ind,n-nums[ind]);
            int not_take = 0+solve(ind-1,n);
            
            return dp[ind][n] = min(take,not_take);
        };
        
        return solve(m-1,n);
    }
};