class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> subset;
    set<vector<int>> s;
    
    void solve(int ind,vector<int>& nums){
        if(ind == nums.size()){
            s.insert(subset);
            return;
        }
        
        // for(int i = ind; i<nums.size(); i++){
        //     if(i>ind && nums[i] == nums[i-1]){
        //         continue;
        //     }
        //     subset.push_back(nums[i]);
        //     solve(i+1,nums);
        //     subset.pop_back();
        //     solve(i+1,nums);
        // }
        subset.push_back(nums[ind]);
        solve(ind+1,nums);
        subset.pop_back();
        solve(ind+1,nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};