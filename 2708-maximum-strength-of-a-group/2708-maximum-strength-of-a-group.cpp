class Solution {
public:
    long long ans = -1e12;
    
    void solve(int ind, long long prod, int size,vector<int> &nums){
        if(ind >= nums.size()){
            if(size)
                ans = max(ans,prod);
            return;
        }
        
        solve(ind+1,prod*nums[ind],size+1,nums);
        solve(ind+1,prod,size,nums);
    }
    
    long long maxStrength(vector<int>& nums) {
        solve(0,1,0,nums);
        return ans;
    }
};