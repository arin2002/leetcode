class Solution {
public:    
    set<vector<int>> s;
    vector<int> temp;
    
    void dfs(int ind, vector<int>& nums, int target){
        if(ind >= nums.size()){
            if(target == 0)
                s.insert(temp);
            return;
        }
        if(target >= nums[ind]){
            temp.push_back(nums[ind]);
            dfs(ind,nums,target-nums[ind]);
            temp.pop_back();
        }
        
        dfs(ind+1,nums,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0,candidates,target);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};