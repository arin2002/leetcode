class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        
        function<int(int,int)>solve = [&](int ind, int sum){
            if(ind == n){
                if(sum%3 == 0)
                    return 0;
                
                return (int)-1e4;
            }
            
            // cout<<sum<<" ";
            if(dp[ind][sum] != -1)
                return dp[ind][sum];
            
            int pick = nums[ind]+solve(ind+1,(sum+nums[ind])%3);
            int not_pick = 0+solve(ind+1,sum%3);
            
            return dp[ind][sum] = max(pick,not_pick);
        };
        
        
        return solve(0,0);
    }
};