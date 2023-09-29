class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size(), up = 1, down = 1;
        
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1])
                up = 0;
            
            if(nums[i] < nums[i-1])
                down = 0;
            
            if(up == 0 && down == 0)
                return 0;
        }
        
        return 1;
    }
};