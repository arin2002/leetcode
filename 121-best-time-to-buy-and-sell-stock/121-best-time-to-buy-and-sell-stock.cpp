class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0;
        int mini = INT_MAX;
        
        int n = nums.size();
        for(int  i = 0; i<n; i++)
        {
            mini = min(nums[i],mini);
            ans = max(ans, nums[i]-mini);
        }
        
        return ans;
    }
};