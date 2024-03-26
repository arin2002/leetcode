class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        int n = nums.size();
        
        for(auto &it: nums){
            if(it > 0){
                mini = min(mini,it);
                maxi = max(maxi,it);
            }
            else{
                it = INT_MAX;
            }
        }
        
        if(mini == maxi){
            if(mini-1 == 0)
                return 2;
            
            return 1;
        }
        
        if(mini == INT_MAX && maxi == INT_MIN){
            return 1;
        }
        
        if(mini<maxi){
            if(mini != 1){
                return 1;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                continue;
            }
            
            int ele = abs(nums[i])-1;
            
            if(ele < n){
                if(nums[ele] == 0){
                    nums[ele] = -1;
                }
                else if(nums[ele] > 0){
                    nums[ele] *= -1;
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        
        return maxi+1;
    }
};