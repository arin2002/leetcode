class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, count = 0;
        int start = 0, n = nums.size();
        
        for(int i = 0; i<n; i++){
            if(nums[i] == 0 && k >= 0){
                k--;
                while(k < 0){
                    if(nums[start++] == 0)
                        k++;
                }
            }
            
            ans = max(ans,i-start+1);
        }
        
        return ans;
    }
};