class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i]){
                nums[start++] = nums[i]; 
            }
        }
        
        for(;start<n; start++){
            nums[start] =  0;
        }
    }
};