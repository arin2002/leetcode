class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 1){
            if(nums[0] == 0)
                k--;
            return k <= 0;
        }
        
        for(int i = 0; i<n; i++){
            if(i == 0){
                if(nums[i] == 0 && nums[i+1]==0){
                    nums[i] = 1;
                    k--;
                }
            }
            else if(i != n-1 && nums[i] == 0){
                if(nums[i-1] == 0 &&  nums[i+1] == 0){
                    nums[i] = 1;
                    k--;
                }
            }
            else{
                if(nums[i] == 0 && nums[i-1] == 0){
                    nums[i] = 1;
                    k--;
                }
            }
        }
        
        return k<=0;
    }
};