class Solution {
public:
    // set<vector<int>> s;
    vector<vector<int>> ans;
    vector<int> temp;
    
    void dfs(int ind, vector<int>& nums, int target){
        if(target<0)
            return;
        
        if(ind >= nums.size()){
            if(target == 0)
                ans.push_back(temp);
            return;
        }
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i = ind; i<nums.size(); i++){
            if(nums[i] > target)
                break;
            
            if(i>ind && nums[i] == nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            dfs(i+1,nums,target-nums[i]);
            temp.pop_back();        
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target);
        // vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};