class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> pre(n,1), suff(n,1);
        
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                pre[i] = pre[i-1]+1;
            }
        }
        
        for(int i = n-2; i>=0; i--){
            if(nums[i] > nums[i+1]){
                suff[i] = suff[i+1]+1;
            }
        }
        
        for(int i = 0; i<n; i++){
            ans += max(pre[i],suff[i]);
        }
        
        return ans;
    }
};