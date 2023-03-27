class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find smallest first
        // 5 4 3 2 1
        // 5>4>3>2>1 ye sequence chalna chaiye
        
        int j = nums.size()-2;
        
        while(j >= 0 && nums[j]>=nums[j+1])
            j--;
        
        if(j<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int i = nums.size()-1;
        while(i>=0 && nums[j]>=nums[i])
            i--;
        
        
        swap(nums[i],nums[j]);
        reverse(nums.begin()+j+1,nums.end());
        
    }
};