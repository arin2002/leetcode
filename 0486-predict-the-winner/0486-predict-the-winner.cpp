class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l, int r, vector<int> &nums){
        if(r<l){
            return 0;
        }
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int a = nums[l]-solve(l+1,r,nums);
        int b = nums[r]-solve(l,r-1,nums);
        
        return dp[l][r] = max(a,b);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        int a = solve(0,nums.size()-1,nums);
        return a>=0;
    }
};