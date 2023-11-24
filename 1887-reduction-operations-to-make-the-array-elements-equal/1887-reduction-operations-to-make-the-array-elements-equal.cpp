class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(),nums.end());
        
        if(n == 1)
            return 0;
        
        for(int i = n-1; i>=0; i--){
            if(nums[i+1] == nums[i]){
                continue;
            }
            else{
                ans += n-i-1;
            }
        }
        
        return ans;
    }
};