class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int i = nums.size()-1, ans = 0;
        
        while(i>=0){
            if(i == 0)
                ans += nums[i];
            else
                ans += nums[i]+nums[i-1];
            i-=3;
        }
        
        return ans;
    }
};