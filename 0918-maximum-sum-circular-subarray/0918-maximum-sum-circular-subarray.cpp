class Solution {
public:
    
    int kadens(vector<int> &nums){
        int ans = -1e8, sum = 0;
        
        for(auto it : nums){
            sum += it;
            ans = max(ans,sum);
            
            if(sum<0)
                sum = 0;
        }
        
        return ans;
    }
    
    int circular(vector<int> &nums){
        int sum = 0, totalSum = 0, ans = 1e8;
        
        for(auto it:nums){
            totalSum += it;
            sum += it;
            ans = min(sum,ans);
            
            if(sum>0)
                sum = 0;
        }
        
        return totalSum-ans;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int maxSubrray = kadens(nums);
        
        // for circular -> totalsum - min subarray sum
        int circularSum = circular(nums);
        
        if(circularSum == 0)
            return maxSubrray;
        
        return max(maxSubrray,circularSum);
    }
};