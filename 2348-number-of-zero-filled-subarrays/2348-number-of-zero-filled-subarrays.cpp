class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long j = 0, i = 0, n = nums.size(), ans = 0;
        
        while(j<n){
            if(nums[j] == 0){
                ans += (j-i+1);
                j++;
            }
            else{
                j++;
                i = j;
            }
        }
        return ans;
    }
};