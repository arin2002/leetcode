class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    
    void solve(int ind, vector<int>& nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = ind; i<nums.size(); i++){
            // swaping
            swap(nums[i],nums[ind]);
            solve(ind+1,nums);
            // agian swapping
            swap(nums[i],nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {        
        solve(0,nums);
        return ans;
    }
};