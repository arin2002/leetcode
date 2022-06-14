class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int c = 1, d = 1;
        for(int i = 0; i<n-1; i++){
            if(nums[i] > nums[i+1])
                c = 0;
            else if(nums[i]<nums[i+1])
                d = 0;
        }
        
        if(c || d)
        return true;
        
        return false;
    }
};