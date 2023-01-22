class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> subset;
    
    void solve(int ind,vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(subset);
            return;
        }
        
        subset.push_back(nums[ind]);
        solve(ind+1,nums);
        subset.pop_back();
        solve(ind+1,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return ans;
    }
};