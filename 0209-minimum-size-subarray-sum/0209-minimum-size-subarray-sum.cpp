class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int ans = INT_MAX, start = 0, n = nums.size();
        int sum = 0;
        
        for(int end = 0; end<n; end++){
            sum += nums[end];
        
            while(sum>=k){
                ans = min(ans,end-start+1);
                sum -= nums[start++];
            }
        }
        
        return ans == INT_MAX ? 0: ans;
    }
};