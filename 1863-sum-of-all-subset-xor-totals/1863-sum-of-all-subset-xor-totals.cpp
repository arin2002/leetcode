class Solution {
public:
    
    int ans = 0;
    
    void solve(int i, vector<int>& nums, int temp){
        
        if(i == nums.size()){
            ans += temp;
            return;   
        }
        
        solve(i+1,nums,temp^nums[i]);        
        solve(i+1,nums,temp);
    }
    
    
    int subsetXORSum(vector<int>& nums) {
        solve(0,nums,0);
        return ans;
    }
};