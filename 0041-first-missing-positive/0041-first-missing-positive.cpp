class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
    
        for(int i = 0; i<n; i++){
            
            // nums[i] != nums[nums[i]-1] this condn is for saving infinite loop
            // nahi daali to infinite jayega ye
            // while isliye kyuki ham lagatar aage ja rahe ha toh while se
            // element ki sahi position jaye isliye kar rahe ha
            while(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        for(int i = 0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        
        return n+1;
    }
};