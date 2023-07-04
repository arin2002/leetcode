class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        for(int i = 0; i<32; i++){
            int ones = 0;
            for(int j = 0; j<n; j++){
                // check set bits
                int set = (nums[j]>>i)&1;
                if(set){
                    ones++;
                }
            }
            
            if(ones%3 != 0){
                ans += (1<<i);
            }
        }
        
        return ans;
    }
};