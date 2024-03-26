class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool flag1 = true;
        int n = nums.size();
        
        for(auto &it: nums){
            if(it == 1){
                flag1 = false;
            }
            else if (it <= 0){
                it = 1;
            }
        }
        
        if(flag1){
            return 1;
        }
        
        for(int i = 0; i<n; i++){
            int ele = abs(nums[i])-1;
            
            if(ele < n && nums[ele] > 0){
                nums[ele] *= -1;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        
        return n+1;
    }
};