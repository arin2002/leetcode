class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xored = nums[0], n = nums.size();
        int ans = 0;
        
        for(int i = 1; i<n; i++){
            xored ^= nums[i];
        }
        
        if(xored == k)
            return ans;
        
        while(xored || k){
            int b1 = xored&1;
            int b2 = k&1;
            
            xored >>= 1;
            k >>= 1;
            
            if(b1^b2){
                ans++;
            }
        }   
        
        return ans;
    }
};