class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int start = 0, ans = 0, n = nums.size();
        
        for(int i = 0; i<n; i++){
            ump[nums[i]]++;
            
            while(ump[nums[i]]>k){
                ump[nums[start++]]--;
            }
            
            ans = max(ans,i-start+1);
        }
        
        return ans;
    }
};