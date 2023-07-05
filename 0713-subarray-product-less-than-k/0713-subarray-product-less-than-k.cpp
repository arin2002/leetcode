class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k<=1)
            return 0;
        
        long long ans = 0, t = 1, start = 0;
        
        for(int i = 0; i<n; i++){
            t *= nums[i];
            
            while(t>=k){
                t /= nums[start++];
            }
            
            ans += i-start+1;
        }
        
        return ans;
    }
};