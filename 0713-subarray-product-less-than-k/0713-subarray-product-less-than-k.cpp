class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        long prod = 1, start = 0, end = 0;
        
        if(k<=1)
            return 0;
        
        for(int i = end; i<n; i++){
            prod *= nums[i];
            
            while(prod >= k){
                prod /= nums[start++];
            }
            
            ans += i-start+1;
        }
        
        return ans;
    }
};