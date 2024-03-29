class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0, l = 0, r = n-1;
        
        while(l < r){
            ans = max(ans,nums[l++]+nums[r--]);
        }
        
        return ans;
    }
};