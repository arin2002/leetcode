class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        
        int stock = nums[0], profit = 0;
        for(int i = 1; i<n; i++){
            if(nums[i] >= stock){
                profit += nums[i] - stock;
                stock = nums[i];
            }
            else{
                stock = nums[i];
            }
        }
        
        return profit;
    }
}; 