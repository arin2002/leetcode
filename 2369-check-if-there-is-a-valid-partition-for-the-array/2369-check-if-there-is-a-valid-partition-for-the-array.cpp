class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        
        function<int(int)>solve = [&](int ind){
            if(ind  >= n){
                return 1;
            }
            
            if(dp[ind] != -1)
                return dp[ind];
            
            int l = 0, r = 0, z = 0;
            if(ind+1<n){
                if(nums[ind] == nums[ind+1]){
                    l = solve(ind+2);
                }
            }
            
            if(ind+2<n){
                if(nums[ind] == nums[ind+1] && nums[ind] == nums[ind+2]){
                    r = solve(ind+3);
                }
                
                if((nums[ind]+1 == nums[ind+1]) && (nums[ind+1]+1 == nums[ind+2])){
                    z = solve(ind+3);
                }
            }
            
            return dp[ind] = l|r|z;
        };
        
        return solve(0);
    }
};