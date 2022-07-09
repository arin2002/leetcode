class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        int count = 1, i= n-1;
        for(; i>=1; i--)
        {
            if(count == 3)
                break;
            
            if(nums[i] != nums[i-1])
                count++;
        }
        
        if(count == 3)
            return nums[i];
        return nums[n-1];
    }
};