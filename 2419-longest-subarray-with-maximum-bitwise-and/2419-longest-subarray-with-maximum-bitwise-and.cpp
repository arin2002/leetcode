class Solution {
public:
    int longestSubarray(vector<int>& nums) {        
        int n = nums.size();
        int ans = 1, temp = 0;
        int maxi = 0;
        for(auto i: nums)
            maxi = max(i,maxi);
        
        for(int i = 0; i<n; i++){
            if(maxi == nums[i]){
                temp++;
            }
            else
                temp = 0;
            
            ans = max(temp,ans);
        }
        return ans;
    }
};