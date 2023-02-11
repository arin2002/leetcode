class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        
        if(nums[0]<nums[j])
            return nums[0];
        
        while(i<j){
            
            int mid = i+(j-i)/2;
            
            if(nums[0]<=nums[mid])
                i = mid+1;
            else
                j = mid;
        }
        
        return nums[i];
    }
};