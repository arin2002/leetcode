class Solution {
public:
    
    vector<long long> dp;
    
    long long solve(int i, vector<vector<int>>& nums){
        if(i >= nums.size()){
            return 0;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        long long take = nums[i][0] + solve(i+nums[i][1]+1,nums);
        long long notTake = 0 + solve(i+1,nums);
        
        return dp[i] = max(take,notTake);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n+2,-1);
        return solve(0,questions);
    }
};