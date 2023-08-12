class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        function<int(int,int)>solve = [&](int x, int y){
            if(x<0 || y<0 || x == n || y == m || nums[x][y] == 1)
                return 0;
            
            if(x == n-1 && y == m-1)
                return 1;
            
            if(dp[x][y] != -1)
                return dp[x][y];
            
            int l = solve(x+1,y);
            int r = solve(x,y+1);
            
            
            return dp[x][y] = l+r;
        };
        
        return solve(0,0);
    }
};