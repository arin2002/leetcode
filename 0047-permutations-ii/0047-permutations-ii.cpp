class Solution {
public:
    
    vector<int> permu, vis;
    // set<vector<int>> st;
    vector<vector<int>> ans;
    
    void solve(int ind, vector<int> &nums){
        if(permu.size() == nums.size()){
            // st.insert(permu);
            ans.push_back(permu);
            return;
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(vis[i])
                continue;
            
            if(i>0 && nums[i] == nums[i-1] && !vis[i-1])
                continue;
            
            vis[i] = 1;
            permu.push_back(nums[i]);
            solve(ind+1,nums);
            vis[i] = 0;
            permu.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis.resize(30);
        
        sort(nums.begin(),nums.end());
        solve(0,nums);
        // vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};